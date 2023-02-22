get_property(languages GLOBAL PROPERTY ENABLED_LANGUAGES)
message("languages: ${languages}")

cmake_minimum_required(VERSION 3.5)
project(HelloApp 
        VERSION 0.1
        DESCRIPTION "PoC - CMake ") 
        
add_executable(HelloAppBinary main.cpp)
target_compile_features(HelloAppBinary PRIVATE cxx_std_20)