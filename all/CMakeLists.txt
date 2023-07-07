# this script adds all subprojects to a single build to allow IDEs understand the full project
# structure.

cmake_minimum_required(VERSION 3.14...3.22)

project(BuildAll LANGUAGES CXX)

# ---- Add Python venv ----
#LIST(APPEND CMAKE_PROGRAM_PATH  "../venv/Scripts" ...)
#find_package (Python3 COMPONENTS Interpreter)
#execute_process (COMMAND "${Python3_EXECUTABLE}" -m venv "../venv")
#
## Here is the trick
### update the environment with VIRTUAL_ENV variable (mimic the activate script)
#set (ENV{VIRTUAL_ENV} "../venv")
### change the context of the search
#set (Python3_FIND_VIRTUALENV FIRST)
### unset Python3_EXECUTABLE because it is also an input variable (see documentation, Artifacts Specification section)
#unset (Python3_EXECUTABLE)
### Launch a new search
#find_package (Python3 COMPONENTS Interpreter Development)
#message("${Python3_EXECUTABLE}")

include(../cmake/tools.cmake)

# needed to generate test target
enable_testing("${Python3_EXECUTABLE}")

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../standalone ${CMAKE_BINARY_DIR}/standalone)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../test ${CMAKE_BINARY_DIR}/test)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../documentation ${CMAKE_BINARY_DIR}/documentation)
