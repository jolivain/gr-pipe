/*
 * Copyright 2022 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(filter.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(c611c10709e1b71250b8250f96eb1507)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/pipe/filter.h>
// pydoc.h is automatically generated in the build directory
#include <filter_pydoc.h>

void bind_filter(py::module& m)
{

    using filter    = ::gr::pipe::filter;


    py::class_<filter, gr::block, gr::basic_block,
        std::shared_ptr<filter>>(m, "filter", D(filter))

        .def(py::init(&filter::make),
           py::arg("in_item_sz"),
           py::arg("out_item_sz"),
           py::arg("relative_rate"),
           py::arg("cmd"),
           D(filter,make)
        )
        




        
        .def("unbuffered",&filter::unbuffered,       
            D(filter,unbuffered)
        )


        
        .def("set_unbuffered",&filter::set_unbuffered,       
            py::arg("unbuffered"),
            D(filter,set_unbuffered)
        )

        ;




}







