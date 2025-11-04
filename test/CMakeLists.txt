add_executable(test_calculator test_calculator.cpp)
target_include_directories(test_calculator 
	                   PUBLIC 
			   ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(test_calculator
	              PUBLIC
                      calculator
)

target_link_libraries(test_calculator
	              PRIVATE
		      Catch2::Catch2WithMain
)

enable_testing()
include(CTest)

include(Catch)
catch_discover_tests(test_calculator)
