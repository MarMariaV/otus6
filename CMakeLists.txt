cmake_minimum_required(VERSION 3.16)
project(otus6)

set(CMAKE_CXX_STANDARD 17)

add_executable(otus6 main.cpp)

if (MSVC)
    target_compile_options(otus6 PRIVATE
            /W4
            )
else ()
    target_compile_options(otus6 PRIVATE
            -Wall -Wextra -pedantic
            )
endif()