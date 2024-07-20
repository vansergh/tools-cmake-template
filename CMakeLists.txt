cmake_minimum_required(VERSION 3.30)

#include cmake functions
include(cmake/functions.cmake)

# Include list of files to be built
set(SOURCES_INCLUDE_PATH *.cpp *.c *.cxx)
set(HEADERS_INCLUDE_PATH *.hpp *.h)

# Exclude list of files (regxp)
set(EXCLUDE_PATH "(/out|/opt|/res)")

# Converting current folder name to PROJECT_NAME
string(REGEX REPLACE "/$" "" CURRENT_FOLDER_ABSOLUTE ${CMAKE_CURRENT_SOURCE_DIR})
string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CURRENT_FOLDER_ABSOLUTE})
set (PROJECT_NAME ${CURRENT_FOLDER})

# Set C++ Standart
set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "-Wall")
set (CMAKE_CXX_FLAGS "-Wextra")
set (CMAKE_CXX_FLAGS "-Werror")
set (CMAKE_CXX_FLAGS "-Wfatal-errors")
set (CMAKE_CXX_FLAGS "-pedantic")
set (CMAKE_CXX_FLAGS "-Wimplicit")
set (CMAKE_CXX_FLAGS "-pedantic-errors")

#set (CMAKE_CXX_FLAGS "-Wno-unused-variable")

# Set project name variable
project(${PROJECT_NAME})

# Search of all sources and headers files
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCES_INCLUDE_PATH})
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/${HEADERS_INCLUDE_PATH})

# Filter sources and headers to build without ignore list
FilterRegex(EXCLUDE ${EXCLUDE_PATH} SOURCES ${SOURCES})

# Print the list of files collected
string(REPLACE ";"  "\n" HEADERS_STR "${HEADERS}")
string(REPLACE ";"  "\n" SOURCES_STR "${SOURCES}")
message(STATUS  "Found headers:")
list(APPEND CMAKE_MESSAGE_INDENT "\t\t")
message(STATUS  "${HEADERS_STR}")
list(POP_BACK CMAKE_MESSAGE_INDENT)
message(STATUS  "Found sources:")
list(APPEND CMAKE_MESSAGE_INDENT "\t\t")
message(STATUS  "${SOURCES_STR}")

#include boost lib
include(cmake/boost.cmake)

#include boost lib
include(cmake/openssl.cmake)

# Build executable with standart libs
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Build executable with boost
TARGET_LINK_LIBRARIES(${PROJECT_NAME} LINK_PUBLIC ${Boost_LIBRARIES})

# Build executable with openssl
TARGET_LINK_LIBRARIES(${PROJECT_NAME} LINK_PUBLIC ${OPENSSL_LIBRARIES})