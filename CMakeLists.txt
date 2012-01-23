
project(SayStuff)
cmake_minimum_required(VERSION 2.8.3)

enable_testing()

find_package( Boost REQUIRED )

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

add_library(
  SayStuff

  src/say.cpp
  )

add_executable(
  HelloWorld

  src/HelloWorld
  )

target_link_libraries(
  HelloWorld

  SayStuff
  )

# Adds a test with no arguments named ${test}. Variable traling
# arguments hold sources for executable
macro( Hello_add_test test )
  add_executable( ${test} ${ARGN} )
  add_test( ${test} ${test} )
  target_link_libraries(
      ${test}

      SayStuff
  )
endmacro()

Hello_add_test(
  TestSay

  src/tests/TestSay.cpp
)

Hello_add_test(
  TestGoodbye

  src/tests/TestGoodbye.cpp
)
