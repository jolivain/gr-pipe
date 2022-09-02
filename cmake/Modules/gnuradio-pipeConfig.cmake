find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_PIPE gnuradio-pipe)

FIND_PATH(
    GR_PIPE_INCLUDE_DIRS
    NAMES gnuradio/pipe/api.h
    HINTS $ENV{PIPE_DIR}/include
        ${PC_PIPE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_PIPE_LIBRARIES
    NAMES gnuradio-pipe
    HINTS $ENV{PIPE_DIR}/lib
        ${PC_PIPE_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-pipeTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_PIPE DEFAULT_MSG GR_PIPE_LIBRARIES GR_PIPE_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_PIPE_LIBRARIES GR_PIPE_INCLUDE_DIRS)
