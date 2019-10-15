cmake_minimum_required(VERSION 3.5)

project(DefaultBackEnd VERSION 0.0.1)

set ( SOURCES
  main.cpp
  Library/ReadFile/source.cpp
  Library/Request/source.cpp
  Library/Response/source.cpp
  Library/Router/source.cpp
)

set ( HEADERS
  Library/ReadFile/header.h
  Library/Request/header.h
  Library/Response/header.h
  Library/Router/header.h
)

add_definitions(-Wall -O2)
add_executable(${PROJECT_NAME}  ${SOURCES} ${HEADERS})

set_target_properties(
  ${PROJECT_NAME} PROPERTIES
  CXX_STANDART 17
  CXX_STANDART_REQUIRED ON
)
