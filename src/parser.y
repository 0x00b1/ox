%skeleton "lalr1.cc" /* -*- C++ -*- */

%require "3.2"

%defines

%define api.token.constructor

%define api.value.type variant

%define parse.assert

%code requires {
  #include <string>

  #include "syntax/syntax.h"

  class Compiler;
}

// The parsing context.
%param {
    Compiler& compiler
}

%locations

%define parse.trace

%define parse.error verbose

%code {
    #include "compiler.hh"
}

%define api.token.prefix {TOK_}

%token END 0 "end of file";

%token
  KEYWORD__8_BIT                         "8-bit"
  KEYWORD_16_BIT                        "16-bit"
  KEYWORD_32_BIT                        "32-bit"
  KEYWORD_64_BIT                        "64-bit"
  KEYWORD_BOOLEAN                       "Boolean"
  KEYWORD_CONSTANT                      "constant"
  KEYWORD_ELSE                          "else"
  KEYWORD_FALSE                         "False"
  KEYWORD_FLOATING_POINT                "Floating-point"
  KEYWORD_IF                            "if"
  KEYWORD_INTEGER                       "Integer"
  KEYWORD_REFERENCE                     "reference"
  KEYWORD_RETURN                        "return"
  KEYWORD_SHARED                        "shared"
  KEYWORD_SIZE                          "Size"
  KEYWORD_SUBROUTINE                    "subroutine"
  KEYWORD_TRUE                          "True"
  KEYWORD_UNSIGNED                      "unsigned"
;

%token <std::string> LITERAL_FLOATING_POINT 
%token <std::string> LITERAL_INTEGER 

%token
  PUNCTUATION_COLON                     ":"
  PUNCTUATION_COMMA                     ","
  PUNCTUATION_LEFT_CURLY_BRACKET        "{"
  PUNCTUATION_LEFT_PARENTHESIS          "("
  PUNCTUATION_LEFT_SQUARE_BRACKET       "["
  PUNCTUATION_LEFTWARDS_ARROW           "←"
  PUNCTUATION_MULTIPLICATION_SIGN       "×"
  PUNCTUATION_RIGHT_CURLY_BRACKET       "}"
  PUNCTUATION_RIGHT_PARENTHESIS         ")"
  PUNCTUATION_RIGHT_SQUARE_BRACKET      "]"
  PUNCTUATION_RIGHTWARDS_ARROW          "→"
  PUNCTUATION_SEMICOLON                 ";"
;

%token <std::string> IDENTIFIER

%type <std::vector<std::shared_ptr<Node::Statement>>> STATEMENTS;
%type <std::shared_ptr<Node::Statement>> STATEMENT;
%type <std::shared_ptr<Node::AssignmentStatement>> ASSIGNMENT_STATEMENT;
%type <std::shared_ptr<Node::BlockStatement>> BLOCK_STATEMENT;
%type <std::shared_ptr<Node::ConditionalStatement>> CONDITIONAL_STATEMENT;
%type <std::shared_ptr<Node::ExpressionStatement>> EXPRESSION_STATEMENT;
%type <std::shared_ptr<Node::Expression>> EXPRESSION;
%type <std::shared_ptr<Node::ArrayExpression>> ARRAY_EXPRESSION;
%type <std::vector<std::shared_ptr<Node::Expression>>> ELEMENTS;
%type <std::shared_ptr<Node::Expression>> ELEMENT;
%type <std::shared_ptr<Node::CallExpression>> CALL_EXPRESSION;
%type <std::vector<std::shared_ptr<Node::Expression>>> ARGUMENTS;
%type <std::shared_ptr<Node::Expression>> ARGUMENT;
%type <std::shared_ptr<Node::IndexExpression>> INDEX_EXPRESSION;
%type <std::shared_ptr<Node::LiteralExpression>> LITERAL_EXPRESSION;
%type <std::shared_ptr<Node::BooleanLiteral>> BOOLEAN_LITERAL;
%type <std::shared_ptr<Node::FloatingPointLiteral>> FLOATING_POINT_LITERAL;
%type <std::shared_ptr<Node::IntegerLiteral>> INTEGER_LITERAL;
%type <std::shared_ptr<Node::PathExpression>> PATH_EXPRESSION;
%type <std::shared_ptr<Node::ReturnStatement>> RETURN_STATEMENT;
%type <std::shared_ptr<Node::Type>> TYPE;
%type <std::shared_ptr<Node::ArrayType>> ARRAY_TYPE;
%type <std::shared_ptr<Node::AnonymousConstant>> ANONYMOUS_CONSTANT;
%type <std::shared_ptr<Node::BooleanType>> BOOLEAN_TYPE;
%type <std::shared_ptr<Node::FloatingPointType>> FLOATING_POINT_TYPE;
%type <std::shared_ptr<Node::FunctionType>> FUNCTION_TYPE;
%type <std::vector<std::shared_ptr<Node::Parameter>>> PARAMETERS;
%type <std::shared_ptr<Node::Parameter>> PARAMETER;
%type <std::shared_ptr<Node::IntegerType>> INTEGER_TYPE;
%type <std::shared_ptr<Node::ReferenceType>> REFERENCE_TYPE;
%type <std::shared_ptr<Node::SliceType>> SLICE_TYPE;

%printer {
    // FIXME:
    //yyo << $$;
    yyo << typeid($$).name();
} <*>;

%%

%start UNIT;

OPERATOR                    : "×"
                            ;
UNIT                        : STATEMENTS
                            ;
STATEMENTS                  : STATEMENT
                            | STATEMENTS STATEMENT
                            ;
STATEMENT                   : ITEM_STATEMENT
                            | ASSIGNMENT_STATEMENT
                            | EXPRESSION_STATEMENT
                            | RETURN_STATEMENT
                            | BLOCK_STATEMENT
                            | CONDITIONAL_STATEMENT
                            ;
ITEM_STATEMENT              : ITEM
                            ;
ITEM                        : MODULE_ITEM
                            | EXTERNAL_PACKAGE_ITEM
                            | SUBROUTINE_ITEM
                            | TYPE_ITEM
                            | CONSTANT_ITEM
                            ;
MODULE_ITEM                 : "module" IDENTIFIER ";"
                            | "module" IDENTIFIER "{" ITEMS "}" ";"
                            ;
ITEMS                       : ITEM
                            | ITEMS ITEM
                            ;
EXTERNAL_PACKAGE_ITEM       : "external" "package" IDENTIFIER ";"
                            | "external" "package" IDENTIFIER "as" IDENTIFIER ";"
                            ;
SUBROUTINE_ITEM             : "subroutine" IDENTIFIER FUNCTION_TYPE BLOCK_STATEMENT
                            ;
TYPE_ITEM                   : "type" IDENTIFIER "←" TYPE ";"
                            ;
CONSTANT_ITEM               : "constant" IDENTIFIER ":" TYPE "←" EXPRESSION ";"
                            ;
ASSIGNMENT_STATEMENT        : PATTERN ":" TYPE "←" EXPRESSION
                            ;
PATTERN                     : LITERAL_PATTERN
                            | IDENTIFIER_PATTERN
                            | WILDCARD_PATTERN
                            | REFERENCE_PATTERN
                            | TUPLE_PATTERN
                            | SLICE_PATTERN
                            | PATH_PATTERN
                            ;
LITERAL_PATTERN             :
                            ;
IDENTIFIER_PATTERN          : IDENTIFIER
                            ;
WILDCARD_PATTERN            : "_"
                            ;
REFERENCE_PATTERN           : "reference" PATTERN
                            ;
TUPLE_PATTERN               : "(" TUPLE_PATTERN_ITEMS ")"
                            ;
TUPLE_PATTERN_ITEMS         : %empty
                            | PATTERN
                            | TUPLE_PATTERN_ITEMS "," PATTERN
                            ;
SLICE_PATTERN               : "[" SLICE_PATTERN_ITEMS "]"
                            ;
SLICE_PATTERN_ITEMS         : PATTERN
                            | SLICE_PATTERN_ITEMS "," PATTERN
                            ;
PATH_PATTERN                : 
                            ;
EXPRESSION_STATEMENT        : EXPRESSION ";" {
                              std::shared_ptr<Node::ExpressionStatement> x(new Node::ExpressionStatement($1));

                              $$ = x;
                            }
                            ;
PREFIX_EXPRESSION           :
                            ;
BINARY_EXPRESSIONS          : BINARY_EXPRESSIONS BINARY_EXPRESSION
                            ;
BINARY_EXPRESSION           :
                            ;
PREFIX_OPERATOR_EXPRESSION  : POSTFIX_OPERATOR_EXPRESSION
                            | OPERATOR POSTFIX_OPERATOR_EXPRESSION
                            ;
INFIX_OPERATOR_EXPRESSION   : OPERATOR PREFIX_OPERATOR_EXPRESSION
                            ;
POSTFIX_OPERATOR_EXPRESSION : POSTFIX_OPERATOR_EXPRESSION OPERATOR
                            | CALL_EXPRESSION
                            | INDEX_EXPRESSION
                            ;
EXPRESSION                  : LITERAL_EXPRESSION
                            | PATH_EXPRESSION
                            | GROUPED_EXPRESSION
                            | ARRAY_EXPRESSION
                            | INDEX_EXPRESSION
                            | TUPLE_EXPRESSION
                            | CALL_EXPRESSION
                            | CLOSURE_EXPRESSION
                            ;
LITERAL_EXPRESSION          : BOOLEAN_LITERAL
                            | FLOATING_POINT_LITERAL
                            | INTEGER_LITERAL
                            ;
BOOLEAN_LITERAL             : "True" {
                              std::shared_ptr<Node::BooleanLiteral> x(new Node::BooleanLiteral(true));

                              $$ = x;
                            }
                            | "False" {
                              std::shared_ptr<Node::BooleanLiteral> x(new Node::BooleanLiteral(false));

                              $$ = x;
                            }
                            ;
FLOATING_POINT_LITERAL      : LITERAL_FLOATING_POINT {
                              std::shared_ptr<Node::FloatingPointLiteral> x(new Node::FloatingPointLiteral($1));

                              $$ = x;
                            }
                            ;
INTEGER_LITERAL             : LITERAL_INTEGER {
                              std::shared_ptr<Node::IntegerLiteral> x(new Node::IntegerLiteral($1));

                              $$ = x;
                            }
                            ;
PATH_EXPRESSION             : IDENTIFIER 
                            ;
GROUPED_EXPRESSION          : "(" EXPRESSION ")"
                            ;
ARRAY_EXPRESSION            : "[" ELEMENTS "]" {
                              std::shared_ptr<Node::ArrayExpression> x(new Node::ArrayExpression($2));

                              $$ = x;
                            }
                            ;
ELEMENTS                    : %empty {
                              $$ = std::vector<std::shared_ptr<Node::Expression>>();
                            }
                            | ELEMENT {
                              $$ = std::vector<std::shared_ptr<Node::Expression>>();

                              $$.push_back($1);
                            }
                            | ELEMENTS "," ELEMENT {
                              std::vector<std::shared_ptr<Node::Expression>> elements = $1;

                              elements.push_back($3);

                              $$ = elements;
                            }
                            ;
ELEMENT                     : EXPRESSION
                            ;
INDEX_EXPRESSION            : EXPRESSION "[" EXPRESSION "]" {
                              std::shared_ptr<Node::IndexExpression> x(new Node::IndexExpression($1, $3));

                              $$ = x;
                            }
                            ;
TUPLE_EXPRESSION            :
                            ;
CALL_EXPRESSION             : EXPRESSION "(" ARGUMENTS ")" {
                              std::shared_ptr<Node::CallExpression> x(new Node::CallExpression($1, $3));

                              $$ = x;
                            }
                            ;
ARGUMENTS                   : %empty {
                              $$ = std::vector<std::shared_ptr<Node::Expression>>();
                            }
                            | ARGUMENT {
                              $$ = std::vector<std::shared_ptr<Node::Expression>>();

                              $$.push_back($1);
                            }
                            | ARGUMENTS "," ARGUMENT {
                              std::vector<std::shared_ptr<Node::Expression>> arguments = $1;

                              arguments.push_back($3);

                              $$ = arguments;
                            }
                            ;
ARGUMENT                    : EXPRESSION
                            ;
CLOSURE_EXPRESSION          :
                            ;
RETURN_STATEMENT            : "return" ";" {
                              std::shared_ptr<Node::ReturnStatement> x(new Node::ReturnStatement());

                              $$ = x;
                            }
                            | "return" EXPRESSION ";" {
                              std::shared_ptr<Node::ReturnStatement> x(new Node::ReturnStatement($2));

                              $$ = x;                              
                            }
                            ;
TYPE                        : ARRAY_TYPE
                            | BOOLEAN_TYPE
                            | FLOATING_POINT_TYPE
                            | FUNCTION_TYPE
                            | INTEGER_TYPE
                            | REFERENCE_TYPE
                            | SLICE_TYPE
                            ;
ARRAY_TYPE                  : "[" TYPE "×" ANONYMOUS_CONSTANT "]" {
                              std::shared_ptr<Node::ArrayType> x(new Node::ArrayType($2));

                              $$ = x;
                            }
                            ;
ANONYMOUS_CONSTANT          : EXPRESSION {
                              std::shared_ptr<Node::AnonymousConstant> x(new Node::AnonymousConstant($1));

                              $$ = x;
                            }
                            ;
BOOLEAN_TYPE                : "Boolean" {
                              std::shared_ptr<Node::BooleanType> x(new Node::BooleanType());

                              $$ = x;
                            }
                            ;
FLOATING_POINT_TYPE         : "32-bit" "Floating-point" {
                              std::shared_ptr<Node::FloatingPointType> x(new Node::FloatingPointType());

                              $$ = x;
                            }
                            | "64-bit" "Floating-point" {
                              std::shared_ptr<Node::FloatingPointType> x(new Node::FloatingPointType());

                              $$ = x;
                            }
                            ;
FUNCTION_TYPE               : "(" PARAMETERS ")" "→" TYPE {
                              std::shared_ptr<Node::FunctionType> x(new Node::FunctionType());

                              $$ = x;
                            }
                            ;
PARAMETERS                  : %empty {
                              $$ = std::vector<std::shared_ptr<Node::Parameter>>();
                            }
                            | PARAMETER {
                              $$ = std::vector<std::shared_ptr<Node::Parameter>>();

                              $$.push_back($1);
                            }
                            | PARAMETERS "," PARAMETER {
                              std::vector<std::shared_ptr<Node::Parameter>> parameters = $1;

                              parameters.push_back($3);

                              $$ = parameters;
                            }
                            ;
PARAMETER                   : IDENTIFIER ":" TYPE {
                              std::shared_ptr<Node::Parameter> x(new Node::Parameter($1, $3));

                              $$ = x;
                            }
                            ;
INTEGER_TYPE                : "unsigned" "8-bit" "Integer" {
                              std::shared_ptr<Node::IntegerType> x(new Node::IntegerType());

                              $$ = x;
                            }
                            | "unsigned" "16-bit" "Integer" {
                              std::shared_ptr<Node::IntegerType> x(new Node::IntegerType());

                              $$ = x;
                            }
                            | "unsigned" "32-bit" "Integer" {
                              std::shared_ptr<Node::IntegerType> x(new Node::IntegerType());

                              $$ = x;
                            }
                            | "unsigned" "64-bit" "Integer" {
                              std::shared_ptr<Node::IntegerType> x(new Node::IntegerType());

                              $$ = x;
                            }
                            | "8-bit" "Integer" {
                              std::shared_ptr<Node::IntegerType> x(new Node::IntegerType());

                              $$ = x;
                            }
                            | "16-bit" "Integer" {
                              std::shared_ptr<Node::IntegerType> x(new Node::IntegerType());

                              $$ = x;
                            }
                            | "32-bit" "Integer" {
                              std::shared_ptr<Node::IntegerType> x(new Node::IntegerType());

                              $$ = x;
                            }
                            | "64-bit" "Integer" {
                              std::shared_ptr<Node::IntegerType> x(new Node::IntegerType());

                              $$ = x;
                            }
                            | "unsigned" "Size" {
                              std::shared_ptr<Node::IntegerType> x(new Node::IntegerType());

                              $$ = x;
                            }
                            | "Size" {
                              std::shared_ptr<Node::IntegerType> x(new Node::IntegerType());

                              $$ = x;
                            }
                            ;
REFERENCE_TYPE              : "reference" TYPE
                            | "shared" "reference" TYPE
                            ;
SLICE_TYPE                  : "[" TYPE "]" {
                              std::shared_ptr<Node::SliceType> x(new Node::SliceType($2));

                              $$ = x;
                            }
                            ;
BLOCK_STATEMENT             : "{" STATEMENTS "}" {
                              std::shared_ptr<Node::BlockStatement> x(new Node::BlockStatement($2));

                              $$ = x;
                            }
                            ;
CONDITIONAL_STATEMENT       : "if" EXPRESSION BLOCK_STATEMENT {

                            }
                            | "if" EXPRESSION BLOCK_STATEMENT "else" BLOCK_STATEMENT {

                            }
                            ;

%%

void yy::parser::error(const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
