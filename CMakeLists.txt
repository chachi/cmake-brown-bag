
project(SayHello)
cmake_minimum_required(VERSION 2.8.3)

enable_testing()

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

add_executable(
  TestSay

  src/tests/TestSay.cpp
  )

target_link_libraries(
  TestSay

  SayHello
  )

add_test( TestSay TestSay)
