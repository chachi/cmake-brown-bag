
project(SayHello)
cmake_minimum_required(VERSION 2.8.3)

add_library(
  SayHello

  src/say.cpp
  )

add_executable(
  HelloWorld

  src/HelloWorld
  )

target_link_libraries(
  HelloWorld

  SayHello
  )