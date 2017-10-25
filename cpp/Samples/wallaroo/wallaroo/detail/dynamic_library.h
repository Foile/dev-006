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

#ifndef WALLAROO_DETAIL_DYNAMIC_LIBRARY_H_
#define WALLAROO_DETAIL_DYNAMIC_LIBRARY_H_

#include <string>
#include "wallaroo/detail/platform_specific_lib_macros.h"
#include WALLAROO_DLL_IMPL_HEADER // select the right OS-specific header-file for PlatformSpecificDynamicLibrary


namespace wallaroo
{
namespace detail
{

// Manage a shared library as a resource. Load it on the ctor
// and unload it on the dtor.
// Export a method to get a function pointer given the symbol name.
class DynamicLibrary : private PlatformSpecificDynamicLibrary
{
public:
    /* Create a DynamicLibrary from the path specified as parameter
    * loading the OS library.
    * @param fileName the path of the dynamic library to load
    * @throw WrongFile if the file does not exist or its format is wrong.
    */
    explicit DynamicLibrary( const std::string& fileName ) :
        PlatformSpecificDynamicLibrary( fileName )
    {
    }
    // Release the OS library
    ~DynamicLibrary()
    {
    }
    /* Return a function pointer to the symbol @c funcName.
    * @param funcName the name of the function in the library to load.
    * @return the function pointer to the symbol required. NULL if the symbol was not found.
    */
    template < typename F >
    F GetFunction( const std::string& funcName )
    {
        return PlatformSpecificDynamicLibrary::GetFunction< F >( funcName );
    }
    /* Returns the platform-specific filename suffix
		for shared libraries (including the period).
		In debug mode, the suffix also includes a
		"d" to specify the debug version of a library.
    */
    static std::string Suffix()
    {
        return PlatformSpecificDynamicLibrary::Suffix();
    }
};

} // namespace detail
} // namespace wallaroo

#endif // WALLAROO_DETAIL_DYNAMIC_LIBRARY_H_
