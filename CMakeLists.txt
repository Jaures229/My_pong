cmake_minimum_required(VERSION 3.10)
project(SDL2DPOng)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(MyPong 
    src/main.cpp
    src/pong.cpp
    src/ball.cpp
    src/paddle.cpp
)

target_link_libraries(MyPong PRIVATE 
    SDL2::SDL2 
    SDL2_ttf::SDL2_ttf
)
