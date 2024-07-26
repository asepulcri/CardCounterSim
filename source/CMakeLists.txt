cmake_minimum_required(VERSION 3.5)
project(CardCounterSim)

set(HeaderFiles
    include/card.h
    include/game.h)

set(SourceFiles
    game.cpp
    main.cpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SourceFiles})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})