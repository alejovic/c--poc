cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME "rest-POCO-server")
set(PROJECT_EXECUTABLE "src/main.cpp")
# set(PROJECT_EXECUTABLE "server/src/hello-world-server.cpp")

## Including source code of the project
set(PROJECT_INCLUDE_DIR ${CMAKE_HOME_DIRECTORY}/src)
set(PROJECT_SOURCE_DIR ${CMAKE_HOME_DIRECTORY}/src)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${PROJECT_EXECUTABLE})

message(STATUS "Project '${PROJECT_NAME}' source path: ${PROJECT_INCLUDE_DIR}")
message(STATUS "Project '${PROJECT_NAME}' include path: ${PROJECT_SOURCE_DIR}")

# defines targets and sources
target_sources(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/src/MyServer.cpp
        ${PROJECT_SOURCE_DIR}/src/router/MyRouter.cpp
        ${PROJECT_SOURCE_DIR}/src/router/resource/Application.cpp
        ${PROJECT_SOURCE_DIR}/src/router/resource/AbstractResource.cpp
        ${PROJECT_SOURCE_DIR}/src/router/resource/ResourceNotFound.cpp
        ${PROJECT_SOURCE_DIR}/src/router/resource/ResourceException.cpp
        ${PROJECT_SOURCE_DIR}/src/router/resource/factory/Factory.cpp
        ${PROJECT_SOURCE_DIR}/src/router/resource/factory/ApplicationFactory.cpp
        PUBLIC
        ${PROJECT_SOURCE_DIR}/src/MyServer.h
        ${PROJECT_SOURCE_DIR}/src/router/MyRouter.h
        ${PROJECT_SOURCE_DIR}/src/router/resource/Application.h
        ${PROJECT_SOURCE_DIR}/src/router/resource/AbstractResource.h
        ${PROJECT_SOURCE_DIR}/src/router/resource/ResourceNotFound.h
        ${PROJECT_SOURCE_DIR}/src/router/resource/ResourceException.h
        ${PROJECT_SOURCE_DIR}/src/router/resource/factory/Factory.h
        ${PROJECT_SOURCE_DIR}/src/router/resource/factory/ApplicationFactory.h
        ${PROJECT_SOURCE_DIR}/src/router/resource/factory/IFactory.h
        )
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_INCLUDE_DIR})


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



