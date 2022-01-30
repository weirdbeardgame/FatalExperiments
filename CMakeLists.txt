cmake_minimum_required(VERSION 3.20.2)

# set the project name
project(FatalExperiments)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/PineClient.cpp )

# add the executable
add_executable(FatalExperiements ${SOURCES} header/pine.h)

target_include_directories(FatalExperiements PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Header)
target_link_libraries(FatalExperiements wsock32 ws2_32)