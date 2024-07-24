cmake_minimum_required(VERSION 3.5)
project(CardCounterSim)

set(HeaderFiles
    include/card.h
    include/game.h)

set(SourceFiles
    game.cpp
    main.cpp)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SourceFiles})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})