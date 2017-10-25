/*******************************************************************************
 * wallaroo - A library for configurable creation and wiring of C++ classes.
 * Copyright (C) 2012 Daniele Pallastrelli
 *
 * This file is part of wallaroo.
 * For more information, see http://wallaroo.googlecode.com/
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

#ifndef WALLAROO_CATALOG_H_
#define WALLAROO_CATALOG_H_

#include <string>
#include <typeinfo>
#include <cassert>
#include "detail/deviceshell.h"
#include "cxx0x.h"
#include "device.h"
#include "class.h"

namespace wallaroo
{

// forward declarations:
class Context;
class UseAsExpression;
class UseExpression;

/**
 * Catalog of devices available for the application.
 *
 * It can create the instances from the name of a class 
 * previously registered with one of the macros
 * WALLAROO_REGISTER(C), WALLAROO_DYNLIB_REGISTER(C)
 * or add the instances.
 *
 * Each item in the catalog is identified by a @c id, with which
 * you can perform a lookup.
 */
class Catalog
{
public:

    /** Default ctor: build an empty catalog.
    */
    Catalog() {}

    /** Look for the element @c itemId in the catalog. It returns a class that
    * provides conversion operator so that you can write eg:
    * \code{.cpp}
    *     shared_ptr< Foo > foo = catalog[ "foo" ];
    * \endcode
    * @param itemId the name of the element
    * @return the element.
    * @throw ElementNotFound if the element does not exist in the catalog.
    */
    detail::DeviceShell operator [] ( const std::string& itemId )
    {
        Devices::iterator i = devices.find( itemId );
        if ( i == devices.end() ) throw ElementNotFound( itemId );
        return detail::DeviceShell( i -> second );
    }

    /** Add a device to the catalog
    * @param id the name of the device to add
    * @param dev the device to add
    * @throw DuplicatedElement if a device with the name @c id is already in the catalog
    */
    void Add( const std::string& id, const cxx0x::shared_ptr< Device >& dev )
    {
        std::pair< Devices::iterator, bool > result = 
            devices.insert( std::make_pair( id, dev ) );
        if ( ! result.second ) throw DuplicatedElement( id );
    }

    /** Instantiate a class having a 2 parameters constructor and add it to the catalog
    * @param id the name of the element to create and add
    * @param className the name of the class to instantiate
    * @param p1 The first parameter of the class constructor
    * @param p2 The second parameter of the class constructor
    * @return the element created.
    * @throw DuplicatedElement if an element with the name @c id is already in the catalog
    * @throw ElementNotFound if @c className class has not been registered
    */
    template < class P1, class P2 >
    detail::DeviceShell Create( const std::string& id, const std::string& className, const P1& p1, const P2& p2 )
    {
        typedef Class< P1, P2 > C;
        C c = C::ForName( className );
        cxx0x::shared_ptr< Device > obj = c.NewInstance( p1, p2 );
        if ( obj.get() == NULL ) throw ElementNotFound( className );
        Add( id, obj );
        return detail::DeviceShell( obj );
    }

    /** Instantiate a class having a 1 parameters constructor and add it to the catalog
    * @param id the name of the element to create and add
    * @param className the name of the class to instantiate
    * @param p The parameter of the class constructor
    * @return the element created.
    * @throw DuplicatedElement if an element with the name @c id is already in the catalog
    * @throw ElementNotFound if @c className class has not been registered
    */
    template < class P >
    detail::DeviceShell Create( const std::string& id, const std::string& className, const P& p )
    {
        typedef Class< P, void > C;
        C c = C::ForName( className );
        cxx0x::shared_ptr< Device > obj = c.NewInstance( p );
        if ( obj.get() == NULL ) throw ElementNotFound( className );
        Add( id, obj );
        return detail::DeviceShell( obj );
    }

    /** Instantiate a class having a default constructor and add it to the catalog
    * @param id the name of the element to create and add
    * @param className the name of the class to instantiate
    * @return the element created.
    * @throw DuplicatedElement if an element with the name @c id is already in the catalog
    * @throw ElementNotFound if @c className class has not been registered
    */
    detail::DeviceShell Create( const std::string& id, const std::string& className )
    {
        typedef Class< void, void > C;
        C c = C::ForName( className );
        cxx0x::shared_ptr< Device > obj = c.NewInstance();
        if ( obj.get() == NULL ) throw ElementNotFound( className );
        Add( id, obj );
        return detail::DeviceShell( obj );
    }

    /** Check if the plugs wiring of the objects inside the container
    * is correct according to the multiplicity declared in the plug definition.
    * @return false if the wiring does not match with the multiplicity declared.
    */
    bool IsWiringOk() const
    {
        return FindWrongMultiplicity().empty();
    }

    /** Check if the plugs wiring of the objects inside the container
    * is correct according to the multiplicity declared in the plug definition.
    * @throw WiringError if the wiring does not match with the multiplicity declared.
    */
    void CheckWiring() const
    {
        const std::string wrongDevice = FindWrongMultiplicity();
        if ( !wrongDevice.empty() ) throw WiringError( wrongDevice );
    }

    /** This method calls Device::Init on every device it contains.
     *  You can call it in the setup phase of your application to perform
     *  the initialization required by each device before the run.
     *  Ideally you should call it *after* wiring and attributes setting, so that
     *  your objects already have dependencies and the right attribute values.
     *  This method rethrows every exception thrown by the devices Init methodm called
     */
    void Init()
    {
        for ( Devices::const_iterator i = devices.begin(); i != devices.end(); ++i )
            i -> second -> Init();
    }

private:

    // copy ctor and assignment operator disabled
    Catalog( const Catalog& );
    Catalog& operator = ( const Catalog& );

    // returns the name of the first devices with wrong multiplicity
    // or the empty string if the test has success
    std::string FindWrongMultiplicity() const
    {
        for( Devices::const_iterator i = devices.begin(); i != devices.end(); ++i )
        {
            if ( ! i -> second -> MultiplicitiesOk() )
                return( i -> first );
        }
        return std::string();
    }

    typedef cxx0x::unordered_map< std::string, cxx0x::shared_ptr< Device > > Devices;
    Devices devices;

    friend class Context;
    friend class UseAsExpression;
    friend class SetExpression;
    friend UseExpression use( const std::string& destClass );
    friend bool IsWiringOk();
    friend void CheckWiring();


    static Catalog*& Current()
    {
        static Catalog* current = NULL;
        return current;
    }
};


// This is a helper class that provides the result of the use().as() function
// useful to concatenate use().as() with of().
class UseAsExpression
{
public:
    UseAsExpression( detail::DeviceShell& _destClass, const std::string& _attribute ) :
      destClass( _destClass ),
      attribute( _attribute )
    {
    }
    void of( const detail::DeviceShell& srcClass )
    {
        // perform the final assignment:
        srcClass.Wire( attribute, destClass );
    }
    // throw CatalogNotSpecified if the current catalog has not been selected with wallaroo_within
    void of ( const std::string& srcClass )
    {
        // default container case
        Catalog* current = Catalog::Current();
        if ( ! current ) throw CatalogNotSpecified();
        of( ( *current )[ srcClass ] );
    }
private:
    const detail::DeviceShell destClass;
    const std::string attribute;
};

// This is a helper class that provides the result of the use() function
// useful to concatenate use() with as().
class UseExpression
{
public:
    explicit UseExpression( const detail::DeviceShell& _destClass )
        : destClass( _destClass )
    {
    }
    UseAsExpression as( const std::string& attribute )
    {
        return UseAsExpression( destClass, attribute );
    }
private:
    detail::DeviceShell destClass;
};


/**
 * This function provides the "use" part in the syntax 
 * @c use( catalog[ "device1" ] ).as( "plug" ).of( catalog[ "device2" ] )
 */
inline UseExpression use( const detail::DeviceShell& destClass )
{
    return UseExpression( destClass );
}

/**
 * This function provides the "use" part in the syntax @c use( "device1" ).as( "plug" ).of( "device2" )
 * @throw CatalogNotSpecified if the current catalog has not been selected including
 * this function in a wallaroo_within section
 */
inline UseExpression use( const std::string& destClass )
{
    // default container case
    Catalog* current = Catalog::Current();
    if ( ! current ) throw CatalogNotSpecified();
    return use( ( *current )[ destClass ] );
}


// This is a helper class that provides the result of the set_attribute().of() function
// useful to concatenate set_attribute().of() with to().
class SetOfExpression
{
public:
    SetOfExpression( const detail::DeviceShell& _device, const std::string& _attribute ) :
        device( _device ), attribute( _attribute ) {}
    template < typename T >
    void to( const T& value )
    {
        // perform the final assignment:
        device.SetAttribute( attribute, value );
    }
private:
    const detail::DeviceShell device;
    const std::string attribute;
};

// This is a helper class that provides the result of the set_attribute() function
// useful to concatenate set_attribute() with of().
class SetExpression
{
public:
    explicit SetExpression( const std::string& att ) : attribute( att ) {}
    SetOfExpression of( const detail::DeviceShell& device ) { return SetOfExpression( device, attribute ); }
    // throw CatalogNotSpecified if the current catalog has not been selected including
    // this function in a wallaroo_within section
    SetOfExpression of( const std::string& device )
    {
        // default container case
        Catalog* current = Catalog::Current( );
        if ( !current ) throw CatalogNotSpecified( );
        return SetOfExpression( ( *current )[ device ], attribute );
    }
private:
    const std::string attribute;
};

/**
* This function provides the "set_attribute" part in the syntax @c set_attribute( "attribute" ).of( "device" ).to( value )
* @throw CatalogNotSpecified if the current catalog has not been selected including
* this function in a wallaroo_within section
*/
inline SetExpression set_attribute( const std::string& attribute ) { return SetExpression( attribute ); }


// Helper class that changes the current catalog on the ctor and
// restores the previous on the dtor
class Context
{
public:
    Context( Catalog& c ) :
      firstTime( true )
    {
        previous = Catalog::Current();
        Catalog::Current() = &c;
    }
    ~Context()
    {
        Catalog::Current() = previous;
    }
    bool FirstTime() const
    {
        return firstTime;
    }
    void Terminate()
    {
        firstTime = false;
    }
private:
    bool firstTime;
    Catalog* previous;
};


/**
 * This preamble creates a scope in which every statement @c use().as().of() will use
 * the catalog @c C withouth the need to specify it every time.
 * So, this code:
 * @code{.cpp}
 * Catalog myCatalog;
 * ...
 * wallaroo_within( myCatalog )
 * {
 *     use( "f136e" ).as( "engine" ).of( "ferrari_f430" );
 *     use( "m139p" ).as( "engine" ).of( "maserati_granturismo" );
 * }
 * @endcode
 * is equivalent to:
 * @code{.cpp}
 * Catalog myCatalog;
 * ...
 * use( myCatalog[ "f136e" ] ).as( "engine" ).of( myCatalog[ "ferrari_f430" ] );
 * use( myCatalog[ "m139p" ] ).as( "engine" ).of( myCatalog[ "maserati_granturismo" ] );
 * @endcode
 *
 * @hideinitializer
 */
#define wallaroo_within( C ) \
    for ( wallaroo::Context context( C ); context.FirstTime(); context.Terminate() )

////////////////////////////////////////////////////////////////////////

} // namespace

#endif