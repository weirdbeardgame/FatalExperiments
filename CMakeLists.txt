cmake_minimum_required(VERSION 4.1.1)

# set the project name
project(FatalExperiments)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/PineClient.cpp )

# add the executable
add_executable(FatalExperiements ${SOURCES})
target_include_directories(FatalExperiements PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Header ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)

if (${CMAKE_HOST_SYSTEM_NAME} MATCHES "Windows")
    target_link_libraries(FatalExperiements wsock32 ws2_32)
endif()