cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME "rest-POCO-server")
#set(PROJECT_EXECUTABLE "src/main.cpp")
set(PROJECT_EXECUTABLE "src/model/db/main.cpp")
# set(PROJECT_EXECUTABLE "server/src/hello-world-server.cpp")

## Including source code of the project
set(PROJECT_INCLUDE_DIR ${CMAKE_HOME_DIRECTORY}/src)
set(PROJECT_SOURCE_DIR ${CMAKE_HOME_DIRECTORY}/src)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${PROJECT_EXECUTABLE})

message(STATUS "Project '${PROJECT_NAME}' source path: ${PROJECT_INCLUDE_DIR}")
message(STATUS "Project '${PROJECT_NAME}' include path: ${PROJECT_SOURCE_DIR}")

## defines targets and sources
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

        ${PROJECT_SOURCE_DIR}/src/model/db/DBConnectionManager.cpp
        ${PROJECT_SOURCE_DIR}/src/model/shared/Entity.cpp
        ${PROJECT_SOURCE_DIR}/src/model/UserEntity.cpp

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

        ${PROJECT_SOURCE_DIR}/src/model/db/DBConnectionManager.h
        ${PROJECT_SOURCE_DIR}/src/model/shared/IEntity.h
        ${PROJECT_SOURCE_DIR}/src/model/shared/Entity.h

        ${PROJECT_SOURCE_DIR}/src/model/UserEntity.h

        )

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_INCLUDE_DIR})


## Postgres package setup (libpqxx)
find_package(PostgreSQL REQUIRED)


## POCO paths and libs setup
set(POCO_PREFIX "/usr/local") # the directory containing "include" and "lib"
set(POCO_INCLUDE_DIR "${POCO_PREFIX}/include")
set(POCO_LIB_DIR "${POCO_PREFIX}/lib")
message(STATUS "POCO_PREFIX library path: ${POCO_PREFIX}")
message(STATUS "POCO_INCLUDE_DIR library path: ${POCO_INCLUDE_DIR}")
message(STATUS "POCO_LIB_DIR library path: ${POCO_LIB_DIR}")

target_include_directories(${PROJECT_NAME} PUBLIC ${POCO_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${POCO_LIB_DIR})

set(POCO_LIBS
        "${POCO_LIB_DIR}/libPocoFoundation.so"
        "${POCO_LIB_DIR}/libPocoUtil.so"
        "${POCO_LIB_DIR}/libPocoNet.so"
        "${POCO_LIB_DIR}/libPocoData.so"
        "${POCO_LIB_DIR}/libPocoJSON.so"
        "${POCO_LIB_DIR}/libPocoXML.so"
        "${POCO_LIB_DIR}/libPocoDataPostgreSQL.so"
        )
message(STATUS "POCO_LIBS library path: ${POCO_LIBS}")        
target_link_libraries(${PROJECT_NAME} PUBLIC ${POCO_LIBS})

# optional
#target_link_libraries(${PROJECT_NAME} PUBLIC PocoFoundation)
#target_link_libraries(${PROJECT_NAME} PUBLIC PocoUtil)
#target_link_libraries(${PROJECT_NAME} PUBLIC PocoNet)
#target_link_libraries(${PROJECT_NAME} PUBLIC PocoData)
#target_link_libraries(${PROJECT_NAME} PUBLIC PocoJSON)
#target_link_libraries(${PROJECT_NAME} PUBLIC PocoXML)
#target_link_libraries(${PROJECT_NAME} PUBLIC PocoDataPostgreSQL)


# cmake -S . -B build/