cmake_minimum_required(VERSION 3.27.7)
project(nqueens)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xclang -fopenmp")

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")

add_executable(run nqueensRecursive.cpp)
add_executable(open nqueensOpenMP.cpp)

target_link_libraries(run PRIVATE OpenMP::OpenMP_CXX)
target_link_libraries(open PRIVATE OpenMP::OpenMP_CXX)



