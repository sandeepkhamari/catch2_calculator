add_library(calculator STATIC calculator.cpp)
target_include_directories(calculator PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_definitions(calculator PRIVATE SRC_MACRO)
target_compile_options(calculator PRIVATE -Wall -Wextra -O2)

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

include(GNUInstallDirs)

message(STATUS "CMAKE_INSTALL_BINDIR: ${CMAKE_INSTALL_BINDIR}")
message(STATUS "CMAKE_INSTALL_INCLUDEDIR: ${CMAKE_INSTALL_INCLUDEDIR}")
message(STATUS "CMAKE_INSTALL_LIBDIR: ${CMAKE_INSTALL_LIBDIR}")

add_executable(calcApp main.cpp)
target_include_directories(calcApp PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(calcApp PRIVATE calculator)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(TARGETS calculator
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

