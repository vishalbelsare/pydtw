///////////////////////////////////////////////////////////////////////////////
//    This file is part of pydtw.
//
//    pydtw is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    pydtw is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with pydtw.  If not, see <http://www.gnu.org/licenses/>.
///////////////////////////////////////////////////////////////////////////////

%module pydtw
%{
/* Includes the header in the wrapper code */
#define SWIG_FILE_WITH_INIT
#include "pydtw.hpp"
%}

%include "typemaps.i"
%include "numpy.i"

%init %{
import_array();
%}

%include "pydtw.hpp"

//%apply (double* INPLACE_ARRAY1, int DIM1) {(double* x, int N)};
//%template(reverseD)  reverse<int, double>;
