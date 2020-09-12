INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_PIPE pipe)

FIND_PATH(
    PIPE_INCLUDE_DIRS
    NAMES pipe/api.h
    HINTS $ENV{PIPE_DIR}/include
        ${PC_PIPE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    PIPE_LIBRARIES
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

include("${CMAKE_CURRENT_LIST_DIR}/pipeTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PIPE DEFAULT_MSG PIPE_LIBRARIES PIPE_INCLUDE_DIRS)
MARK_AS_ADVANCED(PIPE_LIBRARIES PIPE_INCLUDE_DIRS)
