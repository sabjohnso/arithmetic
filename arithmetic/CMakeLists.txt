configure_file(config.hpp.in config.hpp)

add_library(arithmetic_header INTERFACE)
set_target_properties(arithmetic_header PROPERTIES EXPORT_NAME header)
target_include_directories(arithmetic_header
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${arithmetic_INSTALL_INCLUDEDIR}>)

add_library(arithmetic::header ALIAS arithmetic_header)
  
install(TARGETS arithmetic_header
  EXPORT arithmetic_EXPORTS
  RUNTIME DESTINATION ${arithmetic_INSTALL_BINDIR}
  LIBRARY DESTINATION ${arithmetic_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${arithmetic_INSTALL_LIBDIR})

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  arithmetic.hpp
  DESTINATION ${arithmetic_INSTALL_INCLUDEDIR}/arithmetic)

install(DIRECTORY
  details
  DESTINATION ${arithmetic_INSTALL_INCLUDEDIR}/arithmetic
  PATTERN "*.hpp")
