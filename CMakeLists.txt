cmake_minimum_required(VERSION 3.0)

set (PROJECT_NAME
concepts
)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(COMPILE_FLAGS "${COMPILE_FLAGS} -std=c++2a -fconcepts -Wall -O2 -Wno-missing-braces")

set (SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME}
    ${SOURCES}
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
