cmake_minimum_required(VERSION 3.10)

project(HttpServer)
set(HttpServer_VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_definitions(-Wall -O2)

#file(GLOB CPPs "*/*.cpp")

add_executable(${PROJECT_NAME} main.cpp NewProcess/NewProcess.h NewProcess/NewProcess.cpp NewProcess/WriteResponse/WriteResponse.h NewProcess/WriteResponse/WriteResponse.cpp StaticFiles/Check/Check.h StaticFiles/Check/Check.cpp Library/ParseUrl/Parse.h Library/ParseUrl/Parse.cpp StaticFiles/UploadFile/UploadFile.h StaticFiles/UploadFile/UploadFile.cpp)
