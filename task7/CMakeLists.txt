cmake_minimum_required(VERSION 3.5)

project(07.homework)


add_executable(container container.cpp)
set_target_properties(container PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror -g -fsanitize=leak)
endif()

add_subdirectory(gtests)
