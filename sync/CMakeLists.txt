cmake_minimum_required(VERSION 2.0)

project(test)

add_compile_options(-g)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(print_even_odd_cv
print_even_odd_cv.cpp
)

target_link_libraries(print_even_odd_cv
pthread
)
