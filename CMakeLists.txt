
project(SayStuff)
cmake_minimum_required(VERSION 2.8.3)

enable_testing()

find_package( Boost REQUIRED )

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

add_library(
  SayStuff

  src/say.cpp
  )

# Add autoconfigured header for HelloWorld program
option(
    SHOULD_REPEAT 
    "Whether HelloWorld should accept a repeat argument" 
    ON )
set( StringToSay "again" )

configure_file( 
    src/SayString.h.in 
    ${CMAKE_CURRENT_BINARY_DIR}/SayString.h
    )

add_executable(
  HelloWorld

  src/HelloWorld
  )

target_link_libraries(
  HelloWorld

  SayStuff
  )

add_custom_target(
  run_tests

  COMMAND make test
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
  add_dependencies( run_tests ${test} )
endmacro()

Hello_add_test(
  TestSay

  src/tests/TestSay.cpp
)

Hello_add_test(
  TestGoodbye

  src/tests/TestGoodbye.cpp
)
