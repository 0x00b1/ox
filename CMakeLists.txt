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

include_directories(include)
include_directories(src)

add_executable(
    oxc
    src/main.cpp
    ${BISON_PARSER_OUTPUTS}
    ${FLEX_SCANNER_OUTPUTS}
    src/compiler.cpp
    src/generator/Generator.cpp
    src/syntax/AnonymousConstant.cpp
    src/syntax/Argument.cpp
    src/syntax/ArrayExpression.cpp
    src/syntax/ArrayType.cpp
    src/syntax/AssignmentStatement.cpp
    src/syntax/BlockStatement.cpp
        src/syntax/BooleanLiteralExpression.cpp
    src/syntax/BooleanType.cpp
    src/syntax/BottomType.cpp
    src/syntax/CallExpression.cpp
    src/syntax/ClosureExpression.cpp
    src/syntax/ConditionalStatement.cpp
    src/syntax/ConstantItem.cpp
    src/syntax/Expression.cpp
    src/syntax/ExpressionStatement.cpp
    src/syntax/ExternalPackageItem.cpp
        src/syntax/FloatingPointLiteralExpression.cpp
    src/syntax/FloatingPointType.cpp
    src/syntax/FunctionDeclaration.cpp
    src/syntax/FunctionType.cpp
    src/syntax/Identifier.cpp
    src/syntax/IndexExpression.cpp
        src/syntax/IntegerLiteralExpression.cpp
    src/syntax/IntegerType.cpp
    src/syntax/Item.cpp
    src/syntax/ItemStatement.cpp
    src/syntax/Literal.cpp
    src/syntax/LiteralExpression.cpp
    src/syntax/LiteralPattern.cpp
    src/syntax/ModuleItem.cpp
    src/syntax/Name.cpp
    src/syntax/Parameter.cpp
    src/syntax/PathPattern.cpp
    src/syntax/PathType.cpp
    src/syntax/Pattern.cpp
    src/syntax/PointerType.cpp
    src/syntax/Position.cpp
    src/syntax/ReferenceType.cpp
    src/syntax/ReturnStatement.cpp
    src/syntax/SlicePattern.cpp
    src/syntax/SliceType.cpp
    src/syntax/Statement.cpp
    src/syntax/SubroutineItem.cpp
    src/syntax/TupleExpression.cpp
    src/syntax/TuplePattern.cpp
    src/syntax/TupleType.cpp
    src/syntax/Type.cpp
    src/syntax/TypeItem.cpp
    src/syntax/WildcardPattern.cpp
        include/compiler/compiler.h src/syntax/PathExpression.cpp src/syntax/PathExpression.h src/syntax/PrefixExpression.cpp src/syntax/PrefixExpression.h src/syntax/InfixExpression.cpp src/syntax/InfixExpression.h src/syntax/PostfixExpression.cpp src/syntax/PostfixExpression.h src/syntax/Operator.cpp src/syntax/Operator.h src/syntax/OperatorExpression.cpp src/syntax/OperatorExpression.h src/syntax/GroupedExpression.cpp src/syntax/GroupedExpression.h src/syntax/SizeType.cpp src/syntax/SizeType.h src/syntax/ModuleSymbol.cpp src/syntax/ModuleSymbol.h src/syntax/SubroutineSymbolTable.cpp src/syntax/SubroutineSymbolTable.h src/syntax/ClassSymbolTable.cpp src/syntax/ClassSymbolTable.h src/syntax/SymbolTable.cpp src/syntax/SymbolTable.h src/syntax/Symbol.cpp src/syntax/Symbol.h)

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
