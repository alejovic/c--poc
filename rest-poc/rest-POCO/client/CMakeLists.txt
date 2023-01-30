cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME "rest-POCO-client")
set(PROJECT_EXECUTABLE "src/http-get-method.cpp")
# set(PROJECT_EXECUTABLE "src/http-post-method.cpp")


## Including source code of the project
set(PROJECT_INCLUDE_DIR ${CMAKE_HOME_DIRECTORY}/client/src)
set(PROJECT_SOURCE_DIR ${CMAKE_HOME_DIRECTORY}/client/src)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${PROJECT_EXECUTABLE})

message(STATUS "Project '${PROJECT_NAME}' source path: ${PROJECT_INCLUDE_DIR}")
message(STATUS "Project '${PROJECT_NAME}' include path: ${PROJECT_SOURCE_DIR}")


####################################################################################
## Poco Directories setup
####################################################################################

# set(PocoNet_DIR "/usr/include/Poco")
# set(PocoFoundation_DIR "/usr/include/Poco")
message(STATUS "PocoNet_DIR library path: ${PocoNet_DIR}")

## Poco package setup
find_package(Poco CONFIG REQUIRED Foundation Net Util JSON Crypto NetSSL)
find_package(PocoNet REQUIRED)

## set include directory
#target_include_directories(poc PUBLIC "${PocoNet_DIR}")

## set library directory
#target_link_directories(poc PUBLIC "${PocoNet_DIR}")

## link specific object files we need
target_link_libraries(${PROJECT_NAME} PUBLIC Poco::Foundation)
target_link_libraries(${PROJECT_NAME} PUBLIC Poco::Net Poco::Util Poco::JSON)
target_link_libraries(${PROJECT_NAME} PUBLIC Poco::Crypto Poco::NetSSL)



