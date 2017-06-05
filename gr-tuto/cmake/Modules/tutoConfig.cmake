INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_TUTO tuto)

FIND_PATH(
    TUTO_INCLUDE_DIRS
    NAMES tuto/api.h
    HINTS $ENV{TUTO_DIR}/include
        ${PC_TUTO_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    TUTO_LIBRARIES
    NAMES gnuradio-tuto
    HINTS $ENV{TUTO_DIR}/lib
        ${PC_TUTO_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TUTO DEFAULT_MSG TUTO_LIBRARIES TUTO_INCLUDE_DIRS)
MARK_AS_ADVANCED(TUTO_LIBRARIES TUTO_INCLUDE_DIRS)

