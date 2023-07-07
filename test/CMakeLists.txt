cmake_minimum_required(VERSION 3.14...3.22)

project(TestModernCppStarterTests LANGUAGES CXX)

# ---- Options ----

option(ENABLE_TEST_COVERAGE "Enable test coverage" OFF)
option(TEST_INSTALLED_VERSION "Test the version found by find_package" OFF)

# --- Import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/CPM.cmake)
#
#CPMAddPackage("gh:doctest/doctest@2.4.9")
#CPMAddPackage("gh:TheLartians/Format.cmake@1.7.3")
#
#if(TEST_INSTALLED_VERSION)
#  find_package(TestModernCppStarter REQUIRED)
#else()
#  CPMAddPackage(NAME TestModernCppStarter SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)
#endif()
#
## ---- Create binary ----
#
#file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
#add_executable(${PROJECT_NAME} ${sources})
#target_link_libraries(${PROJECT_NAME} doctest::doctest TestModernCppStarter::TestModernCppStarter)
#set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
#
## enable compiler warnings
#if(NOT TEST_INSTALLED_VERSION)
#  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
#    target_compile_options(TestModernCppStarter PUBLIC -Wall -Wpedantic -Wextra -Werror)
#  elseif(MSVC)
#    target_compile_options(TestModernCppStarter PUBLIC /W4 /WX)
#    target_compile_definitions(${PROJECT_NAME} PUBLIC DOCTEST_CONFIG_USE_STD_HEADERS)
#  endif()
#endif()
#
## ---- Add TestModernCppStarterTests ----
#
#enable_testing()
#
## Note: doctest and similar testing frameworks can automatically configure CMake tests. For other
## testing frameworks add the tests target instead: add_test(NAME ${PROJECT_NAME} COMMAND
## ${PROJECT_NAME})
#
#include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
#doctest_discover_tests(${PROJECT_NAME})
#
## ---- code coverage ----
#
#if(ENABLE_TEST_COVERAGE)
#  target_compile_options(TestModernCppStarter PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
#  target_link_options(TestModernCppStarter PUBLIC -fprofile-arcs -ftest-coverage)
#endif()

project(CPMExampleCatch2)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

CPMAddPackage("gh:cpm-cmake/testpack-fibonacci@2.0")
CPMAddPackage("gh:catchorg/Catch2@3.2.1")

CPMAddPackage("gh:gabime/spdlog@1.8.2")

CPMAddPackage("gh:CLIUtils/CLI11@2.3.2")

## Add ZLIB
#set(ZLIB_REPO "https://github.com/madler/zlib.git"
#        CACHE STRING "ZLIB repository location."
#        )
#CPMAddPackage(
#        NAME zlib
#        GIT_REPOSITORY ${ZLIB_REPO}
#        GIT_TAG "v1.2.13"
#        OPTIONS
#        "CMAKE_POSITION_INDEPENDENT_CODE True"
#)
#if(zlib_ADDED)
#    target_include_directories(zlib
#            PUBLIC $<BUILD_INTERFACE:${zlib_BINARY_DIR}>
#            PUBLIC $<INSTALL_INTERFACE:include>)
#    target_include_directories(zlibstatic
#            PUBLIC $<BUILD_INTERFACE:${zlib_BINARY_DIR}>
#            PUBLIC $<INSTALL_INTERFACE:include>)
#
#    message(STATUS "Cmake added local zlib: ${zlib_SOURCE_DIR}")
#else()
#    message(FATAL_ERROR "Cmake failed to add local zlib")
#endif()
#
#find_package (zlib REQUIRED)

CPMAddPackage(
        NAME hdf5
        GIT_TAG hdf5-1_13_1
        GITHUB_REPOSITORY HDFGroup/hdf5
        OPTIONS "HDF5_BUILD_CPP ON"
)

find_package (HDF5 REQUIRED)
message("HDF5_FOUND: ${HDF5_FOUND}")
message("HDF5_VERSION: ${HDF5_VERSION}")
message("HDF5_INCLUDE_DIRS: ${HDF5_INCLUDE_DIRS}")
message("HDF5_C_INCLUDE_DIRS: ${HDF5_C_INCLUDE_DIRS}")
message("HDF5_CXX_INCLUDE_DIRS: ${HDF5_CXX_INCLUDE_DIRS}")

CPMAddPackage(
        NAME h5pp
        VERSION 1.11.0
        GITHUB_REPOSITORY DavidAce/h5pp
        OPTIONS
        "H5PP_PACKAGE_MANAGER find-or-cmake"
)

# spdlog uses fmt and bundles that dependency. If you want to use fmt in your project as well, you
# can let spdlog re-use fmt from CPM.cmake like this:
#
# cmake-format: off
#
# CPMAddPackage("gh:fmtlib/fmt#7.1.3")
# CPMAddPackage(
#   GITHUB_REPOSITORY gabime/spdlog
#   VERSION 1.8.2
#   OPTIONS "SPDLOG_FMT_EXTERNAL 1"
# )
#
# cmake-format: on

# ---- Create binary ----

add_executable(CPMExampleCatch2 source/main_Catch2.cpp source/cli11_test.cpp source/h5pp_test.cpp source/h5pp_wrapper.h)
target_link_libraries(CPMExampleCatch2 fibonacci Catch2::Catch2WithMain spdlog CLI11::CLI11 HDF5 h5pp)
target_include_directories(CPMExampleCatch2 PUBLIC HDF5)
target_compile_features(CPMExampleCatch2 PRIVATE cxx_std_17)

# ---- Enable testing ----

enable_testing()
add_test(CPMExampleCatch2 CPMExampleCatch2)
