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
/* BINDTOOL_HEADER_FILE(source.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(4488156028b5e1b2bed76a5e036bca0a)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/pipe/source.h>
// pydoc.h is automatically generated in the build directory
#include <source_pydoc.h>

void bind_source(py::module& m)
{

    using source = ::gr::pipe::source;


    py::class_<source,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<source>>(m, "source", D(source))

        .def(py::init(&source::make),
             py::arg("out_item_sz"),
             py::arg("cmd"),
             D(source, make))


        ;
}
