cmake_minimum_required(VERSION 3.5)

project(08.homework)

find_package(Threads REQUIRED)

add_executable(topk topk_words-283624-6938d6.cpp)
set_target_properties(topk PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
    target_link_libraries(topk PRIVATE Threads::Threads)
else()
    # lots of warnings and all warnings as errors
    target_compile_options(topk PRIVATE -Wall -Wextra -pedantic -Werror -g)
    target_link_libraries(topk PRIVATE Threads::Threads)
endif()

# add_subdirectory(gtests)
