cmake_minimum_required(VERSION 3.13)  
project(GeometrizeLib)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std:c++latest")
set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std:c++latest")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_UNICODE /DUNICODE")

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/geometrize/geometrize/*.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/geometrize/geometrize/bitmap/*.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/geometrize/geometrize/exporter/*.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/geometrize/geometrize/rasterizer/*.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/geometrize/geometrize/runner/*.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/geometrize/geometrize/shape/*.cpp
                    )

add_library(geometrizeLib ${SRC_FILES})

target_include_directories(geometrizeLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/geometrize)
