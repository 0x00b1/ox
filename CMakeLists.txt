cmake_minimum_required(VERSION 3.13)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/local/opt/llvm/share/cmake/")

project(oxc)

set(CMAKE_CXX_STANDARD 17)

find_package(BISON)
find_package(FLEX)
find_package(LLVM)

BISON_TARGET(
    PARSER
    src/parser.yy
    ${CMAKE_CURRENT_BINARY_DIR}/parser.cc
    COMPILE_FLAGS "--report=all --report-file=bison.txt"
)

FLEX_TARGET(
    SCANNER
    src/scanner.ll
    ${CMAKE_CURRENT_BINARY_DIR}/scanner.cc
)

ADD_FLEX_BISON_DEPENDENCY(SCANNER PARSER)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(.)

add_executable(
    oxc
    src/main.cc
    src/compiler.cc
    ${BISON_PARSER_OUTPUTS}
    ${FLEX_SCANNER_OUTPUTS}
    include/compiler.hh
    include/ast.hh
    include/visitor.hh
    include/generator.hh
    include/expression.hh
    include/syntax.hh
)

include_directories( ${LLVM_INCLUDE_DIRS} )

link_directories( ${LLVM_LIBRARY_DIRS} )

llvm_map_components_to_libnames(
    LLVM_LIBRARIES
    native
)

target_link_libraries(
    oxc
    ${LLVM_LIBRARIES}
)
