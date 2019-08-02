cmake_minimum_required(VERSION 3.13)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/local/opt/llvm/share/cmake/")

project(oxc)

set(CMAKE_CXX_STANDARD 17)

find_package(BISON)
find_package(FLEX)
find_package(LLVM)

BISON_TARGET(
    PARSER
    src/parser.y
    ${CMAKE_CURRENT_BINARY_DIR}/parser.cc
    COMPILE_FLAGS "--report=all --report-file=bison.txt"
)

FLEX_TARGET(
    SCANNER
    src/scanner.l
    ${CMAKE_CURRENT_BINARY_DIR}/scanner.cc
)

ADD_FLEX_BISON_DEPENDENCY(SCANNER PARSER)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(src)

add_executable(
    oxc
    src/main.cpp
    ${BISON_PARSER_OUTPUTS}
    ${FLEX_SCANNER_OUTPUTS}
    src/compiler.cpp
    src/generator.cpp
    src/syntax/AnonymousConstant.cpp
    src/syntax/AnonymousConstant.hh
    src/syntax/Argument.cpp
    src/syntax/Argument.hh
    src/syntax/ArrayExpression.cpp
    src/syntax/ArrayExpression.hh
    src/syntax/ArrayType.cpp
    src/syntax/ArrayType.hh
    src/syntax/AssignmentStatement.cpp
    src/syntax/AssignmentStatement.hh
    src/syntax/BlockStatement.cpp
    src/syntax/BlockStatement.hh
    src/syntax/BooleanLiteral.cpp
    src/syntax/BooleanLiteral.hh
    src/syntax/BooleanType.cpp
    src/syntax/BooleanType.hh
    src/syntax/BottomType.cpp
    src/syntax/BottomType.hh
    src/syntax/CallExpression.cpp
    src/syntax/CallExpression.hh
    src/syntax/ClosureExpression.cpp 
    src/syntax/ClosureExpression.hh 
    src/syntax/ConditionalStatement.cpp
    src/syntax/ConditionalStatement.hh
    src/syntax/ConstantItem.cpp
    src/syntax/ConstantItem.hh
    src/syntax/ExpressionStatement.cpp
    src/syntax/ExpressionStatement.hh
    src/syntax/FloatingPointLiteral.cpp
    src/syntax/FloatingPointLiteral.hh
    src/syntax/FloatingPointType.cpp
    src/syntax/FloatingPointType.hh
    src/syntax/FunctionDeclaration.cpp
    src/syntax/FunctionDeclaration.hh
    src/syntax/FunctionType.cpp
    src/syntax/FunctionType.hh
    src/syntax/Identifier.cpp
    src/syntax/Identifier.hh
    src/syntax/IndexExpression.cpp
    src/syntax/IndexExpression.hh
    src/syntax/IntegerLiteral.cpp
    src/syntax/IntegerLiteral.hh
    src/syntax/IntegerType.cpp
    src/syntax/IntegerType.hh
    src/syntax/ItemStatement.cpp
    src/syntax/ItemStatement.hh
    src/syntax/Literal.cpp
    src/syntax/Literal.hh
    src/syntax/LiteralExpression.cpp
    src/syntax/LiteralExpression.hh
    src/syntax/LiteralPattern.cpp 
    src/syntax/LiteralPattern.hh 
    src/syntax/Name.cpp
    src/syntax/Name.hh
    src/syntax/Node.cpp
    src/syntax/Parameter.cpp
    src/syntax/Parameter.hh
    src/syntax/PathPattern.cpp 
    src/syntax/PathPattern.hh 
    src/syntax/PathType.cpp
    src/syntax/PathType.hh
    src/syntax/PointerType.cpp
    src/syntax/PointerType.hh
    src/syntax/ReferenceType.cpp
    src/syntax/ReferenceType.hh
    src/syntax/ReturnStatement.cpp
    src/syntax/ReturnStatement.hh
    src/syntax/SlicePattern.cpp 
    src/syntax/SlicePattern.hh 
    src/syntax/SliceType.cpp
    src/syntax/SliceType.hh
    src/syntax/SubroutineItem.cpp
    src/syntax/SubroutineItem.hh
    src/syntax/TupleExpression.cpp 
    src/syntax/TupleExpression.hh 
    src/syntax/TuplePattern.cpp 
    src/syntax/TuplePattern.hh
    src/syntax/TupleType.cpp 
    src/syntax/TupleType.hh 
    src/syntax/WildcardPattern.cpp 
    src/syntax/WildcardPattern.hh
        src/syntax/Position.cpp src/syntax/Position.hh src/syntax/ModuleItem.cpp src/syntax/ModuleItem.hh src/syntax/ExternalPackageItem.cpp src/syntax/ExternalPackageItem.hh src/syntax/TypeItem.cpp src/syntax/TypeItem.hh)

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
