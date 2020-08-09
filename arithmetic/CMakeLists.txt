configure_file(config.hpp.in config.hpp)

add_library(arithmetic INTERFACE)
target_include_directories(arithmetic
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${arithmetic_INSTALL_INCLUDEDIR}>)

add_library(arithmetic::arithmetic ALIAS arithmetic)
  
install(TARGETS arithmetic
  EXPORT arithmetic_EXPORTS
  RUNTIME DESTINATION ${arithmetic_INSTALL_BINDIR}
  LIBRARY DESTINATION ${arithmetic_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${arithmetic_INSTALL_LIBDIR})

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  DESTINATION ${arithmetic_INSTALL_INCLUDEDIR})
