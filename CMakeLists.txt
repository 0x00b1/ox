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
    src/ConcreteSyntax/AnonymousConstant.cpp
    src/ConcreteSyntax/Argument.cpp
    src/ConcreteSyntax/ArrayExpression.cpp
    src/ConcreteSyntax/ArrayType.cpp
    src/ConcreteSyntax/AssignmentStatement.cpp
    src/ConcreteSyntax/BlockStatement.cpp
    src/ConcreteSyntax/BooleanLiteralExpression.cpp
    src/ConcreteSyntax/BooleanType.cpp
    src/ConcreteSyntax/BottomType.cpp
    src/ConcreteSyntax/CallExpression.cpp
    src/ConcreteSyntax/ClosureExpression.cpp
    src/ConcreteSyntax/ConditionalStatement.cpp
    src/ConcreteSyntax/ConstantItem.cpp
    src/ConcreteSyntax/Expression.cpp
    src/ConcreteSyntax/ExpressionStatement.cpp
    src/ConcreteSyntax/ExternalPackageItem.cpp
    src/ConcreteSyntax/FloatingPointLiteralExpression.cpp
    src/ConcreteSyntax/FloatingPointType.cpp
    src/ConcreteSyntax/FunctionDeclaration.cpp
    src/ConcreteSyntax/FunctionType.cpp
    src/ConcreteSyntax/GroupedExpression.cpp
    src/ConcreteSyntax/Identifier.cpp
    src/ConcreteSyntax/IdentifierPattern.cpp
    src/ConcreteSyntax/IndexExpression.cpp
    src/ConcreteSyntax/InfixExpression.cpp
    src/ConcreteSyntax/IntegerLiteralExpression.cpp
    src/ConcreteSyntax/IntegerType.cpp
    src/ConcreteSyntax/Item.cpp
    src/ConcreteSyntax/ItemStatement.cpp
    src/ConcreteSyntax/Literal.cpp
    src/ConcreteSyntax/LiteralExpression.cpp
    src/ConcreteSyntax/LiteralPattern.cpp
    src/ConcreteSyntax/ModuleItem.cpp
    src/ConcreteSyntax/ModuleSymbol.cpp
    src/ConcreteSyntax/Name.cpp
    src/ConcreteSyntax/Operator.cpp
    src/ConcreteSyntax/OperatorExpression.cpp
    src/ConcreteSyntax/Parameter.cpp
    src/ConcreteSyntax/PathExpression.cpp
    src/ConcreteSyntax/PathPattern.cpp
    src/ConcreteSyntax/PathType.cpp
    src/ConcreteSyntax/Pattern.cpp
    src/ConcreteSyntax/PointerType.cpp
    src/ConcreteSyntax/Position.cpp
    src/ConcreteSyntax/PostfixExpression.cpp
    src/ConcreteSyntax/PrefixExpression.cpp
    src/ConcreteSyntax/ReferencePattern.cpp
    src/ConcreteSyntax/ReferencePattern.h
    src/ConcreteSyntax/ReferenceType.cpp
    src/ConcreteSyntax/ReturnStatement.cpp
    src/ConcreteSyntax/SizeType.cpp
    src/ConcreteSyntax/SlicePattern.cpp
    src/ConcreteSyntax/SliceType.cpp
    src/ConcreteSyntax/Statement.cpp
    src/ConcreteSyntax/SubroutineItem.cpp
    src/ConcreteSyntax/TupleExpression.cpp
    src/ConcreteSyntax/TuplePattern.cpp
    src/ConcreteSyntax/TupleType.cpp
    src/ConcreteSyntax/Type.cpp
    src/ConcreteSyntax/TypeItem.cpp
    src/ConcreteSyntax/Unit.cpp
    src/ConcreteSyntax/WildcardPattern.cpp
    src/generator/Generator.cpp
    src/SymbolTable/ClassSymbolTable.cpp
    src/SymbolTable/SubroutineSymbolTable.cpp
    src/SymbolTable/Symbol.cpp
    src/SymbolTable/SymbolTable.cpp
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
