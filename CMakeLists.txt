cmake_minimum_required(VERSION 3.13)
project(ox)

set(CMAKE_CXX_STANDARD 17)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(PARSER parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cc)

FLEX_TARGET(SCANNER scanner.ll ${CMAKE_CURRENT_BINARY_DIR}/scanner.cc)

ADD_FLEX_BISON_DEPENDENCY(SCANNER PARSER)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(.)

add_executable(ox main.cc compiler.cc ${BISON_PARSER_OUTPUTS} ${FLEX_SCANNER_OUTPUTS} compiler.hh ox.cc ox.hh)
