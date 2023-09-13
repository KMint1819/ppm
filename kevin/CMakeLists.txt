add_executable(kevin
    test.cpp
    test.h
)
target_include_directories(kevin 
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR})