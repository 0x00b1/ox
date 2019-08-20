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
        src/AbstractSyntax/AnonymousConstant.cpp
        src/AbstractSyntax/Argument.cpp
        src/AbstractSyntax/ArrayExpression.cpp
        src/AbstractSyntax/ArrayType.cpp
        src/AbstractSyntax/AssignmentStatement.cpp
        src/AbstractSyntax/BlockStatement.cpp
        src/AbstractSyntax/BooleanLiteralExpression.cpp
        src/AbstractSyntax/BooleanType.cpp
        src/AbstractSyntax/BottomType.cpp
        src/AbstractSyntax/CallExpression.cpp
        src/AbstractSyntax/ClosureExpression.cpp
        src/AbstractSyntax/ConditionalStatement.cpp
        src/AbstractSyntax/ConstantDeclaration.cpp
        src/AbstractSyntax/Expression.cpp
        src/AbstractSyntax/ExpressionStatement.cpp
        src/AbstractSyntax/ImportDeclaration.cpp
        src/AbstractSyntax/FloatingPointLiteralExpression.cpp
        src/AbstractSyntax/FloatingPointType.cpp
        src/AbstractSyntax/FunctionDeclaration.cpp
        src/AbstractSyntax/FunctionType.cpp
        src/AbstractSyntax/GroupedExpression.cpp
        src/AbstractSyntax/Identifier.cpp
        src/AbstractSyntax/IdentifierPattern.cpp
        src/AbstractSyntax/IndexExpression.cpp
        src/AbstractSyntax/InfixExpression.cpp
        src/AbstractSyntax/IntegerLiteralExpression.cpp
        src/AbstractSyntax/IntegerType.cpp
        src/AbstractSyntax/Declaration.cpp
        src/AbstractSyntax/DeclarationStatement.cpp
        src/AbstractSyntax/Literal.cpp
        src/AbstractSyntax/LiteralExpression.cpp
        src/AbstractSyntax/LiteralPattern.cpp
        src/AbstractSyntax/ModuleDeclaration.cpp
        src/AbstractSyntax/Name.cpp
        src/AbstractSyntax/Operator.cpp
        src/AbstractSyntax/OperatorExpression.cpp
        src/AbstractSyntax/Parameter.cpp
        src/AbstractSyntax/PathExpression.cpp
        src/AbstractSyntax/PathPattern.cpp
        src/AbstractSyntax/PathType.cpp
        src/AbstractSyntax/Pattern.cpp
        src/AbstractSyntax/PointerType.cpp
        src/AbstractSyntax/Position.cpp
        src/AbstractSyntax/PostfixExpression.cpp
        src/AbstractSyntax/PrefixExpression.cpp
        src/AbstractSyntax/ReferencePattern.cpp
        src/AbstractSyntax/ReferencePattern.h
        src/AbstractSyntax/ReferenceType.cpp
        src/AbstractSyntax/ReturnStatement.cpp
        src/AbstractSyntax/SizeType.cpp
        src/AbstractSyntax/SlicePattern.cpp
        src/AbstractSyntax/SliceType.cpp
        src/AbstractSyntax/Statement.cpp
        src/AbstractSyntax/SubroutineDeclaration.cpp
        src/AbstractSyntax/TupleExpression.cpp
        src/AbstractSyntax/TuplePattern.cpp
        src/AbstractSyntax/TupleType.cpp
        src/AbstractSyntax/Type.cpp
        src/AbstractSyntax/TypeDeclaration.cpp
        src/AbstractSyntax/TranslationUnit.cpp
        src/AbstractSyntax/WildcardPattern.cpp
        src/NameResolution/NameResolution.cpp
        src/SymbolTable/ClassSymbolTable.cpp
        src/SymbolTable/SubroutineSymbolTable.cpp
        src/SymbolTable/Symbol.cpp
        src/SymbolTable/SymbolTable.cpp
        include/ox/Visitor.h
        src/AbstractSyntax/ClassDeclaration.cpp
        src/SymbolTable/ModuleSymbolTable.cpp
        src/AbstractSyntax/FunctionPrototype.cpp
        src/AbstractSyntax/PathSegment.cpp
        src/AbstractSyntax/Path.cpp
        src/AbstractSyntax/PrefixOperation.cpp
        src/AbstractSyntax/InfixOperation.cpp
        src/AbstractSyntax/PlaceExpression.cpp
        src/AbstractSyntax/ValueExpression.cpp
        src/AbstractSyntax/VariableDeclaration.cpp src/AbstractSyntax/VariableDeclaration.h)

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
