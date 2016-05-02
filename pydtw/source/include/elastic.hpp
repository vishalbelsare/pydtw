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

#ifndef PYDTW_ELASTIC_HPP
#define PYDTW_ELASTIC_HPP

///////////////////////////////////////////////////////////////////////////////
// optional OpenMP support
///////////////////////////////////////////////////////////////////////////////

#if defined(PYDTW_ENABLE_OPENMP)
#include <omp.h>
#endif

///////////////////////////////////////////////////////////////////////////////
// includes
///////////////////////////////////////////////////////////////////////////////

#include <vector>
#define PYDTW_CONSTANTS_INFINITY (9999999)

///////////////////////////////////////////////////////////////////////////////
// elastic measures
///////////////////////////////////////////////////////////////////////////////

template <
    typename index_t,
    typename value_t,
    typename funct_t>
value_t elastic_dtw(
    value_t * series0,
    index_t   length0,
    value_t * series1,
    index_t   length1,
    funct_t   metric) {

    // convenience
    const index_t lane_i = length0+1;
    const index_t lane_j = length1+1;
    const index_t area = lane_i*lane_j;
    std::vector<value_t> penalty(area);

    // initialize penalty matrix
    for (index_t j = 1; j < lane_j; j++)
        penalty[0*lane_j+j] = PYDTW_CONSTANTS_INFINITY;
    for (index_t i = 1; i < lane_i; i++)
        penalty[i*lane_j+0] = PYDTW_CONSTANTS_INFINITY;
    penalty[0] = 0;

    for (index_t i = 0; i < lane_i; i++)
        for (index_t j = 0; j < lane_j; j++) {
            const value_t residue = metric(series0, series1);
        }

    return penalty[area-1];
}

#endif
