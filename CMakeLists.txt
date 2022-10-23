cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(data-structures-lib)

add_executable(data-structures)

target_compile_features(data-structures PRIVATE cxx_std_20)

target_include_directories(data-structures PRIVATE
 data-structures-lib
)