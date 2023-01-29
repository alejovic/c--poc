cmake_minimum_required(VERSION 3.25)
project(poc)

add_executable(poc http-get-method.cpp)
#add_executable(poc http-post-method.cpp)

set(CMAKE_CXX_STANDARD 17)

# set Poco Directories
#set(PocoNet_DIR "/usr/include/Poco")
#set(PocoFoundation_DIR "/usr/include/Poco")

message(STATUS "PocoNet_DIR library path: ${PocoNet_DIR}")
#
find_package(Poco CONFIG REQUIRED Foundation Net Util JSON Crypto NetSSL)
find_package(PocoNet REQUIRED)


## set include directory
#target_include_directories(poc PUBLIC "${PocoNet_DIR}")

## set library directory
#target_link_directories(poc PUBLIC "${PocoNet_DIR}")

## link specific object files we need
target_link_libraries(poc PUBLIC Poco::Foundation)
target_link_libraries(poc PUBLIC Poco::Net Poco::Util Poco::JSON)
target_link_libraries(poc PUBLIC Poco::Crypto Poco::NetSSL)



