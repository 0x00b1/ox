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
        src/ConcreteSyntax/Identifier.cpp
        src/ConcreteSyntax/IndexExpression.cpp
        src/ConcreteSyntax/IntegerLiteralExpression.cpp
        src/ConcreteSyntax/IntegerType.cpp
        src/ConcreteSyntax/Item.cpp
        src/ConcreteSyntax/ItemStatement.cpp
        src/ConcreteSyntax/Literal.cpp
        src/ConcreteSyntax/LiteralExpression.cpp
        src/ConcreteSyntax/LiteralPattern.cpp
        src/ConcreteSyntax/ModuleItem.cpp
        src/ConcreteSyntax/Name.cpp
        src/ConcreteSyntax/Parameter.cpp
        src/ConcreteSyntax/PathPattern.cpp
        src/ConcreteSyntax/PathType.cpp
        src/ConcreteSyntax/Pattern.cpp
        src/ConcreteSyntax/PointerType.cpp
        src/ConcreteSyntax/Position.cpp
        src/ConcreteSyntax/ReferenceType.cpp
        src/ConcreteSyntax/ReturnStatement.cpp
        src/ConcreteSyntax/SlicePattern.cpp
        src/ConcreteSyntax/SliceType.cpp
        src/ConcreteSyntax/Statement.cpp
        src/ConcreteSyntax/SubroutineItem.cpp
        src/ConcreteSyntax/TupleExpression.cpp
        src/ConcreteSyntax/TuplePattern.cpp
        src/ConcreteSyntax/TupleType.cpp
        src/ConcreteSyntax/Type.cpp
        src/ConcreteSyntax/TypeItem.cpp
        src/ConcreteSyntax/WildcardPattern.cpp
        include/compiler/compiler.h
        src/ConcreteSyntax/PathExpression.cpp
        src/ConcreteSyntax/PathExpression.h
        src/ConcreteSyntax/PrefixExpression.cpp
        src/ConcreteSyntax/PrefixExpression.h
        src/ConcreteSyntax/InfixExpression.cpp
        src/ConcreteSyntax/InfixExpression.h
        src/ConcreteSyntax/PostfixExpression.cpp
        src/ConcreteSyntax/PostfixExpression.h
        src/ConcreteSyntax/Operator.cpp
        src/ConcreteSyntax/Operator.h
        src/ConcreteSyntax/OperatorExpression.cpp
        src/ConcreteSyntax/OperatorExpression.h
        src/ConcreteSyntax/GroupedExpression.cpp
        src/ConcreteSyntax/GroupedExpression.h
        src/ConcreteSyntax/SizeType.cpp
        src/ConcreteSyntax/SizeType.h
        src/ConcreteSyntax/ModuleSymbol.cpp
        src/ConcreteSyntax/ModuleSymbol.h
        src/symbol/SubroutineSymbolTable.cpp
        src/symbol/SubroutineSymbolTable.h
        src/symbol/ClassSymbolTable.cpp
        src/symbol/ClassSymbolTable.h
        src/symbol/SymbolTable.cpp
        src/symbol/SymbolTable.h
        src/symbol/Symbol.cpp
        src/symbol/Symbol.h
        include/symbol/symbol.h
        src/ConcreteSyntax/ReferencePattern.cpp
        src/ConcreteSyntax/ReferencePattern.h
        src/ConcreteSyntax/Unit.cpp
        src/ConcreteSyntax/Unit.h
        src/ConcreteSyntax/IdentifierPattern.cpp src/ConcreteSyntax/IdentifierPattern.h)

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
