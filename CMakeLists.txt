cmake_minimum_required(VERSION 3.22)

project(HtmlTemplating)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_library(
    RenderLibrary
    render.h
    render.c++
)

add_library(
    Elements
    elements.h
    elements.c++
)

target_link_libraries(Elements RenderLibrary)

add_executable(
    Main
    main.c++
)

target_link_libraries(Main RenderLibrary Elements)

if(FALSE)
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        c9461a9b55ba954df0489bab6420eb297bed846b
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    hello_test
    hello_test.c++
)

target_link_libraries(
    hello_test
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
endif()