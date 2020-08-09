cmake_minimum_required(VERSION 3.12)

project(arithmetic VERSION 0.1.0 LANGUAGES C CXX)

option(arithmetic_BUILD_TESTING "Build the arithmetic tests" ON)

include(GNUInstallDirs)
set(arithmetic_INSTALL_BINDIR ${CMAKE_INSTALL_BINDIR})
set(arithmetic_INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR})
set(arithmetic_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR})
set(arithmetic_INSTALL_CONFDIR ${arithmetic_INSTALL_LIBDIR}/cmake/arithmetic-${PROJECT_VERSION})

list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)
include(arithmetic_deps)

add_subdirectory(arithmetic)

if(arithmetic_BUILD_TESTING)
  include(CTest)
  if(BUILD_TESTING)
    add_subdirectory(arithmetic_testing)
  endif()
endif()

install(EXPORT arithmetic_EXPORTS
  NAMESPACE arithmetic::
  FILE arithmetic-exports.cmake
  DESTINATION ${arithmetic_INSTALL_CONFDIR})

configure_file(arithmetic-config.cmake.in arithmetic-config.cmake)
install(FILES ${PROJECT_BINARY_DIR}/arithmetic-config.cmake
  DESTINATION ${arithmetic_INSTALL_CONFDIR})








