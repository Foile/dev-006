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

#include "bin.h"

Bin Bin::_00( "00" );
Bin Bin::_0( "0" );
Bin Bin::_1( "1" );
Bin Bin::_2( "2" );
Bin Bin::_3( "3" );
Bin Bin::_4( "4" );
Bin Bin::_5( "5" );
Bin Bin::_6( "6" );
Bin Bin::_7( "7" );
Bin Bin::_8( "8" );
Bin Bin::_9( "9" );
Bin Bin::_10( "10" );
Bin Bin::_11( "11" );
Bin Bin::_12( "12" );
Bin Bin::_13( "13" );
Bin Bin::_14( "14" );
Bin Bin::_15( "15" );
Bin Bin::_16( "16" );
Bin Bin::_17( "17" );
Bin Bin::_18( "18" );
Bin Bin::_19( "19" );
Bin Bin::_20( "20" );
Bin Bin::_21( "21" );
Bin Bin::_22( "22" );
Bin Bin::_23( "23" );
Bin Bin::_24( "24" );
Bin Bin::_25( "25" );
Bin Bin::_26( "26" );
Bin Bin::_27( "27" );
Bin Bin::_28( "28" );
Bin Bin::_29( "29" );
Bin Bin::_30( "30" );
Bin Bin::_31( "31" );
Bin Bin::_32( "32" );
Bin Bin::_33( "33" );
Bin Bin::_34( "34" );
Bin Bin::_35( "35" );
Bin Bin::_36( "36" );

Bin::Bin( const Bin& bin ) :
    value( bin.value )
{
}

Bin::Bin( const std::string& _value ) :
    value( _value )
{
}

const std::string& Bin::Value() const
{
    return value;
}

bool Bin::operator==( const Bin& other) const
{
    return value == other.value;
}

bool Bin::operator<( const Bin& other) const
{
    return value < other.value;
}

Bin& Bin::operator=( const Bin& rhs )
{
    if ( this == &rhs )
        return *this;        // Yes, so skip assignment, and just return *this.

    value = rhs.value;

    return *this;
}
