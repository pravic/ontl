// { dg-options "-std=gnu++0x" }
// { dg-require-atomic-builtins "" }

// Copyright (C) 2009 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#include <exception>
#include <ntl-tests-common.hxx>

STLX_DEFAULT_TESTGROUP_NAME("std::nested_exception#rethrow_nested");

template<> template<> void tut::to::test<01>() 
{
  bool test __attribute__((unused)) = false;

  try
  {
    try
    {
      throw 42;
    }
    catch (...)
    {
      std::nested_exception e;
      e.rethrow_nested();
    }
  }
  catch(const int& i)
  {
    test = true;
    VERIFY( i == 42 );
  }

  VERIFY( test );
}
