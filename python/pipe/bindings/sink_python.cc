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
/* BINDTOOL_HEADER_FILE(sink.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(d590e111df0faeb048025df66be57da0)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/pipe/sink.h>
// pydoc.h is automatically generated in the build directory
#include <sink_pydoc.h>

void bind_sink(py::module& m)
{

    using sink = ::gr::pipe::sink;


    py::class_<sink, gr::sync_block, gr::block, gr::basic_block, std::shared_ptr<sink>>(
        m, "sink", D(sink))

        .def(py::init(&sink::make), py::arg("in_item_sz"), py::arg("cmd"), D(sink, make))


        .def("unbuffered", &sink::unbuffered, D(sink, unbuffered))


        .def("set_unbuffered",
             &sink::set_unbuffered,
             py::arg("unbuffered"),
             D(sink, set_unbuffered))

        ;
}