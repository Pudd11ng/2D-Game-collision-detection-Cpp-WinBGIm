cmake_minimum_required(VERSION 3.10)

# Set the project name
project(NinjaMario)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set MinGW as the compiler
# Change the path if MinGW located at different directory
set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")

# Include directories for header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/winbgim/include)

# Link directories for libraries
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/winbgim/lib)

# Add the source files
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Add the executable
add_executable(NinjaMario main.cpp ${SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/winbgim/lib/libbgi.a) 

# Link against the necessary libraries
target_link_libraries(NinjaMario
    bgi
    gdi32
    comdlg32
    uuid
    oleaut32
    ole32
)

# Add MinGW-specific flags
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/images DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
