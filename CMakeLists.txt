
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

# Adds a test with no arguments named ${test}. Variable traling
# arguments hold sources for executable
macro( Hello_add_test test )
  add_executable( ${test} ${ARGN} )
  add_test( ${test} ${test} )
  target_link_libraries(
      ${test}

      SayHello
  )
endmacro()

Hello_add_test(
  TestSay

  src/tests/TestSay.cpp
)
