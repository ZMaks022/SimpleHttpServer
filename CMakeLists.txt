cmake_minimum_required(VERSION 3.5)

project(HttpServer VERSION 0.0.3)

set ( SOURCES
  main.cpp
  NewProcess/NewProcess.cpp
  NewProcess/WriteResponse/WriteResponse.cpp
  StaticFiles/Check/Check.cpp
  StaticFiles/UploadFile/UploadFile.cpp
  Library/ParseUrl/Parse.cpp
  Options/Option.cpp
)

set ( HEADERS
  NewProcess/NewProcess.h
  NewProcess/WriteResponse/WriteResponse.h
  StaticFiles/Check/Check.h
  StaticFiles/UploadFile/UploadFile.h
  Library/ParseUrl/Parse.h
  Options/Option.h
)

add_definitions(-Wall -O2)
add_executable(${PROJECT_NAME}  ${SOURCES} ${HEADERS})

set_target_properties(
  ${PROJECT_NAME} PROPERTIES
  CXX_STANDART 17
  CXX_STANDART_REQUIRED ON
)
