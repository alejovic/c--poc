
cmake_minimum_required(VERSION 3.25)
set(PROJECT_NAME "HelloAppBinary")

#set(CXX_STANDARD_REQUIRED ON) # Make C++ a hard requirement
#set(CMAKE_CXX_STANDARD 20) # Default C++ Standard for targets

project(${PROJECT_NAME} 
        VERSION 0.1
        DESCRIPTION "PoC - CMake ") 
        
message(STATUS "Project '${PROJECT_NAME}' CMAKE_HOME_DIRECTORY path: ${CMAKE_HOME_DIRECTORY}")
message(STATUS "Project '${PROJECT_NAME}' CMAKE_CURRENT_SOURCE_DIR path: ${CMAKE_CURRENT_SOURCE_DIR}")

## Including source code of the project
set(PROJECT_INCLUDE_DIR ${CMAKE_HOME_DIRECTORY}/include)

########################################################################################
add_executable(${PROJECT_NAME} main.cpp src/dog.cpp)

# DEPENDENCY :: operations
add_library(operations STATIC src/operations.cpp)
target_include_directories(operations PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_features(operations PUBLIC cxx_std_11)
message(STATUS "Project '${PROJECT_NAME}' - operations feature included.")

# DEPENDENCY :: logger
add_library(logger STATIC logger/src/logger.cpp)
target_include_directories(logger PUBLIC logger/include)
target_compile_features(logger PUBLIC cxx_std_11)
message(STATUS "Project '${PROJECT_NAME}' - logger feature included.")

# TARGET :: Project
target_compile_features(HelloAppBinary PUBLIC cxx_std_20)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_INCLUDE_DIR})
message(STATUS "Project '${PROJECT_NAME}' include path: ${PROJECT_INCLUDE_DIR}")

target_link_libraries(${PROJECT_NAME} PUBLIC operations)
target_link_libraries(${PROJECT_NAME} PUBLIC logger)
########################################################################################

