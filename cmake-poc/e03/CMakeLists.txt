
cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "HelloAppBinary")

project(${PROJECT_NAME} 
        VERSION 0.1
        DESCRIPTION "PoC - CMake ") 
        
message(STATUS "Project '${PROJECT_NAME}' CMAKE_HOME_DIRECTORY path: ${CMAKE_HOME_DIRECTORY}")
message(STATUS "Project '${PROJECT_NAME}' CMAKE_CURRENT_SOURCE_DIR path: ${CMAKE_CURRENT_SOURCE_DIR}")

## Including source code of the project
set(PROJECT_INCLUDE_DIR ${CMAKE_HOME_DIRECTORY}/include)


########################################################################################
## Option 1: GLOBING
## Deprecated: Bad practice https://stackoverflow.com/questions/1027247/
# file(GLOB_RECURSE SOURCES_FILES src/*.cpp)
# message(STATUS "Project '${PROJECT_NAME}' SOURCES_FILES path: ${SOURCES_FILES}")
# add_executable(${PROJECT_NAME} main.cpp ${SOURCES_FILES})

## TARGET
# target_compile_features(HelloAppBinary PRIVATE cxx_std_20)
#
# target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE_DIR})
# message(STATUS "Project '${PROJECT_NAME}' include path: ${PROJECT_INCLUDE_DIR}")
########################################################################################

########################################################################################

#add_executable(${PROJECT_NAME} main.cpp src/dog.cpp src/operations.cpp)
## TARGET
# target_compile_features(HelloAppBinary PRIVATE cxx_std_20)
#
# target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE_DIR})
# message(STATUS "Project '${PROJECT_NAME}' include path: ${PROJECT_INCLUDE_DIR}")
########################################################################################

########################################################################################

add_executable(${PROJECT_NAME} main.cpp)

set(PROJECT_SOURCE_DIR ${CMAKE_HOME_DIRECTORY}/src)
message(STATUS "Project '${PROJECT_NAME}' source path: ${PROJECT_SOURCE_DIR}")

## TARGET
target_compile_features(HelloAppBinary PRIVATE cxx_std_20)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE_DIR})
message(STATUS "Project '${PROJECT_NAME}' include path: ${PROJECT_INCLUDE_DIR}")

target_sources(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/dog.cpp
        ${PROJECT_SOURCE_DIR}/operations.cpp

        PRIVATE
        ${PROJECT_INCLUDE_DIR}/dog.h
        ${PROJECT_INCLUDE_DIR}/operations.h
        )
########################################################################################
