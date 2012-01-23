
project(SayHello)
cmake_minimum_required(VERSION 2.8.3)

enable_testing()

find_package( Boost REQUIRED )

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

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
