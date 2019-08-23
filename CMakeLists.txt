cmake_minimum_required(VERSION 3.14)
project(WebServer)

set(CMAKE_CXX_STANDARD 17)

add_executable(WebServer main.cpp NewProcess/NewProcess.h NewProcess/NewProcess.cpp NewProcess/WriteResponse/WriteResponse.h NewProcess/WriteResponse/WriteResponse.cpp StaticFiles/Check/Check.h StaticFiles/Check/Check.cpp Library/ParseUrl/Parse.h Library/ParseUrl/Parse.cpp StaticFiles/UploadFile/UploadFile.h StaticFiles/UploadFile/UploadFile.cpp)