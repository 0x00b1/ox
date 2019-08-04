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
  KEYWORD_AS                            "as"
  KEYWORD_BOOLEAN                       "Boolean"
  KEYWORD_CONSTANT                      "constant"
  KEYWORD_ELSE                          "else"
  KEYWORD_FALSE                         "False"
  KEYWORD_FLOATING_POINT                "Floating-point"
  KEYWORD_IF                            "if"
  KEYWORD_INTEGER                       "Integer"
  KEYWORD_IS                            "is"
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
  PUNCTUATION_DIVISION_SIGN             "÷"
  PUNCTUATION_LEFT_CURLY_BRACKET        "{"
  PUNCTUATION_LEFT_PARENTHESIS          "("
  PUNCTUATION_LEFT_SQUARE_BRACKET       "["
  PUNCTUATION_LEFTWARDS_ARROW           "←"
  PUNCTUATION_MINUS_SIGN                "−"
  PUNCTUATION_MULTIPLICATION_SIGN       "×"
  PUNCTUATION_PLUS_SIGN                 "+"
  PUNCTUATION_RIGHT_CURLY_BRACKET       "}"
  PUNCTUATION_RIGHT_PARENTHESIS         ")"
  PUNCTUATION_RIGHT_SQUARE_BRACKET      "]"
  PUNCTUATION_RIGHTWARDS_ARROW          "→"
  PUNCTUATION_SEMICOLON                 ";"
  PUNCTUATION_GREATER_THAN_OR_EQUAL_TO  "≥"
  PUNCTUATION_LESS_THAN_OR_EQUAL_TO     "≤"
  PUNCTUATION_GREATER_THAN_SIGN         ">"
  PUNCTUATION_LESS_THAN_SIGN            "<"
;

%token <std::string> IDENTIFIER

%type <std::vector<std::shared_ptr<Node::Node>>> UNIT;
%type <std::vector<std::shared_ptr<Node::Statement>>> STATEMENTS;
%type <std::shared_ptr<Node::Statement>> STATEMENT;
%type <std::shared_ptr<Node::ExpressionStatement>> EXPRESSION_STATEMENT;
%type <std::shared_ptr<Node::OperatorExpression>> OPERATOR_EXPRESSION;
%type <std::shared_ptr<Node::PrefixExpression>> PREFIX_EXPRESSION;
%type <Node::Operator> OPERATOR;
%type <std::shared_ptr<Node::PostfixExpression>> POSTFIX_EXPRESSION;
%type <std::shared_ptr<Node::PathExpression>> PATH_EXPRESSION;
%type <std::shared_ptr<Node::LiteralExpression>> LITERAL_EXPRESSION;
%type <std::shared_ptr<Node::BooleanLiteral>> BOOLEAN_LITERAL;
%type <std::shared_ptr<Node::FloatingPointLiteral>> FLOATING_POINT_LITERAL;
%type <std::shared_ptr<Node::IntegerLiteral>> INTEGER_LITERAL;
%type <std::shared_ptr<Node::ArrayExpression>> ARRAY_EXPRESSION;
%type <std::vector<std::shared_ptr<Node::Expression>>> ARRAY_EXPRESSION_ELEMENTS;
%type <std::shared_ptr<Node::ClosureExpression>> CLOSURE_EXPRESSION;
%type <std::shared_ptr<Node::TupleExpression>> TUPLE_EXPRESSION;
%type <std::vector<std::shared_ptr<Node::Expression>>> TUPLE_EXPRESSION_ELEMENTS;
%type <std::shared_ptr<Node::CallExpression>> CALL_EXPRESSION;
%type <std::vector<std::shared_ptr<Node::Expression>>> CALL_EXPRESSION_ARGUMENTS;
%type <std::shared_ptr<Node::Expression>> CALL_EXPRESSION_ARGUMENT;
%type <std::shared_ptr<Node::IndexExpression>> INDEX_EXPRESSION;
%type <std::vector<std::shared_ptr<Node::InfixExpression>>> INFIX_EXPRESSIONS;
%type <std::shared_ptr<Node::InfixExpression>> INFIX_EXPRESSION;
%type <std::shared_ptr<Node::AssignmentStatement>> ASSIGNMENT_STATEMENT;
%type <std::shared_ptr<Node::ItemStatement>> ITEM_STATEMENT;
%type <std::shared_ptr<Node::ConditionalStatement>> CONDITIONAL_STATEMENT;
%type <std::shared_ptr<Node::ReturnStatement>> RETURN_STATEMENT;
%type <std::shared_ptr<Node::BlockStatement>> BLOCK_STATEMENT;
%type <std::shared_ptr<Node::Pattern>> PATTERN;
%type <std::shared_ptr<Node::WildcardPattern>> WILDCARD_PATTERN;
%type <std::shared_ptr<Node::TuplePattern>> TUPLE_PATTERN;
%type <std::shared_ptr<Node::Type>> TYPE;
%type <std::shared_ptr<Node::FunctionType>> FUNCTION_TYPE;
%type <std::vector<std::shared_ptr<Node::Parameter>>> FUNCTION_TYPE_PARAMETERS;
%type <std::shared_ptr<Node::Parameter>> FUNCTION_TYPE_PARAMETER;
%type <std::shared_ptr<Node::ArrayType>> ARRAY_TYPE;
%type <std::shared_ptr<Node::AnonymousConstant>> ANONYMOUS_CONSTANT;
%type <std::shared_ptr<Node::BooleanType>> BOOLEAN_TYPE;
%type <std::shared_ptr<Node::FloatingPointType>> FLOATING_POINT_TYPE;
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

UNIT                        : STATEMENTS
                            ;
STATEMENTS                  : STATEMENTS STATEMENT {
                              std::vector<std::shared_ptr<Node::Statement>> statements = $1;

                              statements.push_back($2);

                              $$ = statements;
                            }
                            | STATEMENT {
                              $$ = std::vector<std::shared_ptr<Node::Statement>>();

                              $$.push_back($1);
                            }
                            ;
STATEMENT                   : EXPRESSION_STATEMENT
                            | ASSIGNMENT_STATEMENT
                            | ITEM_STATEMENT
                            | CONDITIONAL_STATEMENT
                            | RETURN_STATEMENT
                            | BLOCK_STATEMENT
                            ;
EXPRESSION_STATEMENT        : OPERATOR_EXPRESSION ";" {
                              std::shared_ptr<Node::ExpressionStatement> expression(new Node::ExpressionStatement($1));

                              $$ = expression;
                            }
                            ;
OPERATOR_EXPRESSION         : PREFIX_EXPRESSION INFIX_EXPRESSIONS {
                              std::shared_ptr<Node::OperatorExpression> expression(new Node::OperatorExpression($1, $2));

                              $$ = expression;
                            }
                            | PREFIX_EXPRESSION {
                              std::shared_ptr<Node::OperatorExpression> expression(new Node::OperatorExpression($1));

                              $$ = expression;
                            }
                            ;
PREFIX_EXPRESSION           : OPERATOR POSTFIX_EXPRESSION {
                              std::shared_ptr<Node::PrefixExpression> expression(new Node::PrefixExpression($2));

                              $$ = expression;
                            }
                            | POSTFIX_EXPRESSION {
                              std::shared_ptr<Node::PrefixExpression> expression(new Node::PrefixExpression($1));

                              $$ = expression;
                            }
                            ;
OPERATOR                    : "+"
                            | "÷"
                            | "×"
                            | "<"
                            | ">"
                            | "−"
                            | "≤"
                            | "≥"
                            ;
POSTFIX_EXPRESSION          : PATH_EXPRESSION
                            | LITERAL_EXPRESSION
                            | ARRAY_EXPRESSION
                            | CLOSURE_EXPRESSION
                            | GROUPED_EXPRESSION
                            | TUPLE_EXPRESSION
                            | POSTFIX_EXPRESSION OPERATOR
                            | CALL_EXPRESSION
                            | INDEX_EXPRESSION
                            ;
PATH_EXPRESSION             : IDENTIFIER 
                            ;
LITERAL_EXPRESSION          : BOOLEAN_LITERAL
                            | FLOATING_POINT_LITERAL
                            | INTEGER_LITERAL
                            ;
BOOLEAN_LITERAL             : "True"
                            | "False"
                            ;
FLOATING_POINT_LITERAL      : LITERAL_FLOATING_POINT
                            ;
INTEGER_LITERAL             : LITERAL_INTEGER
                            ;
ARRAY_EXPRESSION            : "[" ARRAY_EXPRESSION_ELEMENTS "]"
                            ;
ARRAY_EXPRESSION_ELEMENTS   : ARRAY_EXPRESSION_ELEMENTS "," OPERATOR_EXPRESSION
                            | OPERATOR_EXPRESSION
                            ;
CLOSURE_EXPRESSION          :
                            ;
GROUPED_EXPRESSION          : "(" OPERATOR_EXPRESSION ")"
                            ;
TUPLE_EXPRESSION            : "(" TUPLE_EXPRESSION_ELEMENTS ")"
                            ;
TUPLE_EXPRESSION_ELEMENTS   : TUPLE_EXPRESSION_ELEMENTS "," OPERATOR_EXPRESSION
                            | OPERATOR_EXPRESSION
                            ;
CALL_EXPRESSION             : OPERATOR_EXPRESSION "(" CALL_EXPRESSION_ARGUMENTS ")"
                            ;
CALL_EXPRESSION_ARGUMENTS   : CALL_EXPRESSION_ARGUMENTS "," CALL_EXPRESSION_ARGUMENT
                            | CALL_EXPRESSION_ARGUMENT
                            ;
CALL_EXPRESSION_ARGUMENT    : OPERATOR_EXPRESSION
                            ;
INDEX_EXPRESSION            : OPERATOR_EXPRESSION "[" OPERATOR_EXPRESSION "]"
                            ;
INFIX_EXPRESSIONS           : INFIX_EXPRESSIONS INFIX_EXPRESSION {
                              std::vector<std::shared_ptr<Node::InfixExpression>> infix_expressions = $1;

                              infix_expressions.push_back($2);

                              $$ = infix_expressions;
                            }
                            | INFIX_EXPRESSION {
                              $$ = std::vector<std::shared_ptr<Node::InfixExpression>>();

                              $$.push_back($1);
                            }
                            ;
INFIX_EXPRESSION            : OPERATOR PREFIX_EXPRESSION {
                              std::shared_ptr<Node::InfixExpression> expression(new Node::InfixExpression($1, $2));

                              $$ = expression;
                            }
                            ;
ASSIGNMENT_STATEMENT        : PATTERN ":" TYPE "←" OPERATOR_EXPRESSION ";"
                            ;
ITEM_STATEMENT              : ITEM
                            ;
ITEM                        : MODULE_ITEM
                            | EXTERNAL_PACKAGE_ITEM
                            | CONSTANT_ITEM
                            | TYPE_ITEM
                            | SUBROUTINE_ITEM
                            ;
MODULE_ITEM                 : "module" IDENTIFIER "{" ITEMS "}" ";"
                            | "module" IDENTIFIER ";"
                            ;
ITEMS                       : ITEMS ITEM
                            | ITEM
                            ;
EXTERNAL_PACKAGE_ITEM       : "external" "package" IDENTIFIER "as" IDENTIFIER ";"
                            | "external" "package" IDENTIFIER ";"
                            ;
CONSTANT_ITEM               : "constant" IDENTIFIER ":" TYPE "←" OPERATOR_EXPRESSION ";"
                            ;
TYPE_ITEM                   : "type" IDENTIFIER "←" TYPE ";"
                            ;
SUBROUTINE_ITEM             : "subroutine" IDENTIFIER FUNCTION_TYPE BLOCK_STATEMENT
                            ;
CONDITIONAL_STATEMENT       : "if" OPERATOR_EXPRESSION BLOCK_STATEMENT "else" BLOCK_STATEMENT ";"
                            | "if" OPERATOR_EXPRESSION BLOCK_STATEMENT ";"
                            ;
RETURN_STATEMENT            : "return" ";"
                            | "return" OPERATOR_EXPRESSION ";"
                            ;
BLOCK_STATEMENT             : "{" STATEMENTS "}"
                            ;
PATTERN                     : WILDCARD_PATTERN
                            | IDENTIFIER_PATTERN
                            | TUPLE_PATTERN
                            | LITERAL_PATTERN
                            | REFERENCE_PATTERN
                            | SLICE_PATTERN
                            ;
WILDCARD_PATTERN            : "_"
                            ;
IDENTIFIER_PATTERN          : IDENTIFIER
                            ;
REFERENCE_PATTERN           : "reference" PATTERN
                            ;
TUPLE_PATTERN               : "(" TUPLE_PATTERN_ITEMS ")"
                            ;
TUPLE_PATTERN_ITEMS         : TUPLE_PATTERN_ITEMS "," PATTERN
                            | PATTERN
                            ;
LITERAL_PATTERN             :
                            ;
SLICE_PATTERN               : "[" SLICE_PATTERN_ITEMS "]"
                            ;
SLICE_PATTERN_ITEMS         : SLICE_PATTERN_ITEMS "," PATTERN
                            | PATTERN
                            ;
TYPE                        : FUNCTION_TYPE
                            | ARRAY_TYPE
                            | BOOLEAN_TYPE
                            | FLOATING_POINT_TYPE
                            | INTEGER_TYPE
                            | REFERENCE_TYPE
                            | SLICE_TYPE
                            ;
FUNCTION_TYPE               : "(" FUNCTION_TYPE_PARAMETERS ")" "→" TYPE
                            ;
FUNCTION_TYPE_PARAMETERS    : FUNCTION_TYPE_PARAMETERS "," FUNCTION_TYPE_PARAMETER
                            | FUNCTION_TYPE_PARAMETER
                            | %empty
                            ;
FUNCTION_TYPE_PARAMETER     : IDENTIFIER ":" TYPE
                            ;
ARRAY_TYPE                  : "[" TYPE "×" ANONYMOUS_CONSTANT "]"
                            ;
ANONYMOUS_CONSTANT          : OPERATOR_EXPRESSION
                            ;
BOOLEAN_TYPE                : "Boolean"
                            ;
FLOATING_POINT_TYPE         : "32-bit" "Floating-point"
                            | "64-bit" "Floating-point"
                            ;
INTEGER_TYPE                : "unsigned"  "8-bit" "Integer"
                            |             "8-bit" "Integer"
                            | "unsigned" "16-bit" "Integer"
                            |            "16-bit" "Integer"
                            | "unsigned" "32-bit" "Integer"
                            |            "32-bit" "Integer"
                            | "unsigned" "64-bit" "Integer"
                            |            "64-bit" "Integer"
                            | "unsigned"          "Size"
                            |                     "Size"
                            ;
REFERENCE_TYPE              : "reference" TYPE
                            | "shared" "reference" TYPE
                            ;
SLICE_TYPE                  : "[" TYPE "]"
                            ;

%%

void yy::parser::error(const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
