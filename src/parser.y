%skeleton "lalr1.cc" /* -*- C++ -*- */

%require "3.2"

%defines

%define api.token.constructor

%define api.value.type variant

%define parse.assert

%code requires {
  #include <string>

  #include "ox/syntax.h"

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

%token <std::string> IDENTIFIER;

%type <std::shared_ptr<Node::Unit>> UNIT;
%type <std::vector<std::shared_ptr<Node::Statement>>> STATEMENTS;
%type <std::shared_ptr<Node::Statement>> STATEMENT;
%type <std::shared_ptr<Node::ExpressionStatement>> EXPRESSION_STATEMENT;
%type <std::shared_ptr<Node::OperatorExpression>> OPERATOR_EXPRESSION;
%type <std::shared_ptr<Node::PrefixExpression>> PREFIX_EXPRESSION;
%type <std::string> OPERATION;
%type <std::shared_ptr<Node::PostfixExpression>> POSTFIX_EXPRESSION;
%type <std::shared_ptr<Node::PathExpression>> PATH_EXPRESSION;
%type <std::shared_ptr<Node::LiteralExpression>> LITERAL_EXPRESSION;
%type <std::shared_ptr<Node::BooleanLiteralExpression>> BOOLEAN_LITERAL_EXPRESSION;
%type <std::shared_ptr<Node::FloatingPointLiteralExpression>> FLOATING_POINT_LITERAL_EXPRESSION;
%type <std::shared_ptr<Node::IntegerLiteralExpression>> INTEGER_LITERAL_EXPRESSION;
%type <std::shared_ptr<Node::ArrayExpression>> ARRAY_EXPRESSION;
%type <std::vector<std::shared_ptr<Node::Node>>> ARRAY_EXPRESSION_ELEMENTS;
%type <std::shared_ptr<Node::GroupedExpression>> GROUPED_EXPRESSION;
%type <std::shared_ptr<Node::TupleExpression>> TUPLE_EXPRESSION;
%type <std::vector<std::shared_ptr<Node::Node>>> TUPLE_EXPRESSION_ELEMENTS;
%type <std::shared_ptr<Node::CallExpression>> CALL_EXPRESSION;
%type <std::vector<std::shared_ptr<Node::Node>>> CALL_EXPRESSION_ARGUMENTS;
%type <std::shared_ptr<Node::IndexExpression>> INDEX_EXPRESSION;
%type <std::vector<std::shared_ptr<Node::InfixExpression>>> INFIX_EXPRESSIONS;
%type <std::shared_ptr<Node::InfixExpression>> INFIX_EXPRESSION;
%type <std::shared_ptr<Node::AssignmentStatement>> ASSIGNMENT_STATEMENT;
%type <std::shared_ptr<Node::ItemStatement>> ITEM_STATEMENT;
%type <std::shared_ptr<Node::Item>> ITEM;
%type <std::shared_ptr<Node::ModuleItem>> MODULE_ITEM;
%type <std::vector<std::shared_ptr<Node::Item>>> ITEMS;
%type <std::shared_ptr<Node::ExternalPackageItem>> EXTERNAL_PACKAGE_ITEM;
%type <std::shared_ptr<Node::SubroutineItem>> SUBROUTINE_ITEM;
%type <std::shared_ptr<Node::ConstantItem>> CONSTANT_ITEM;
%type <std::shared_ptr<Node::TypeItem>> TYPE_ITEM;
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
%type <std::shared_ptr<Node::SizeType>> SIZE_TYPE;
%type <std::shared_ptr<Node::ReferenceType>> REFERENCE_TYPE;
%type <std::shared_ptr<Node::SliceType>> SLICE_TYPE;
%type <std::vector<std::shared_ptr<Node::Pattern>>> TUPLE_PATTERN_ITEMS;
%type <std::shared_ptr<Node::ReferencePattern>> REFERENCE_PATTERN;
%type <std::shared_ptr<Node::IdentifierPattern>> IDENTIFIER_PATTERN;

%printer {
    // FIXME:
    //yyo << $$;
    yyo << typeid($$).name();
} <*>;

%%

%start UNIT;

UNIT                              : STATEMENTS {
                                    std::shared_ptr<Node::Unit> unit(new Node::Unit($1));

                                    compiler.unit = unit;
                                  }
                                  ;
STATEMENTS                        : STATEMENTS STATEMENT {
                                    std::vector<std::shared_ptr<Node::Statement>> statements = $1;

                                    statements.push_back($2);

                                    $$ = statements;
                                  }
                                  | STATEMENT {
                                    $$ = std::vector<std::shared_ptr<Node::Statement>>();

                                    $$.push_back($1);
                                  }
                                  ;
STATEMENT                         : EXPRESSION_STATEMENT {
                                    std::shared_ptr<Node::Statement> statement(new Node::Statement($1));

                                    $$ = statement;
                                  }
                                  | ASSIGNMENT_STATEMENT {
                                    std::shared_ptr<Node::Statement> statement(new Node::Statement($1));

                                    $$ = statement;
                                  }
                                  | ITEM_STATEMENT {
                                    std::shared_ptr<Node::Statement> statement(new Node::Statement($1));

                                    $$ = statement;
                                  }
                                  | CONDITIONAL_STATEMENT {
                                    std::shared_ptr<Node::Statement> statement(new Node::Statement($1));

                                    $$ = statement;
                                  }
                                  | RETURN_STATEMENT {
                                    std::shared_ptr<Node::Statement> statement(new Node::Statement($1));

                                    $$ = statement;
                                  }
                                  | BLOCK_STATEMENT {
                                    std::shared_ptr<Node::Statement> statement(new Node::Statement($1));

                                    $$ = statement;
                                  }
                                  ;
EXPRESSION_STATEMENT              : OPERATOR_EXPRESSION ";" {
                                    std::shared_ptr<Node::ExpressionStatement> expression_statement(new Node::ExpressionStatement($1));

                                    $$ = expression_statement;
                                  }
                                  ;
OPERATOR_EXPRESSION               : PREFIX_EXPRESSION INFIX_EXPRESSIONS {
                                    std::shared_ptr<Node::OperatorExpression> operator_expression(new Node::OperatorExpression($1, $2));

                                    $$ = operator_expression;
                                  }
                                  | PREFIX_EXPRESSION {
                                    std::shared_ptr<Node::OperatorExpression> operator_expression(new Node::OperatorExpression($1));

                                    $$ = operator_expression;
                                  }
                                  ;
PREFIX_EXPRESSION                 : OPERATION POSTFIX_EXPRESSION {
                                    std::shared_ptr<Node::PrefixExpression> prefix_expression(new Node::PrefixExpression($1, $2));

                                    $$ = prefix_expression;
                                  }
                                  | POSTFIX_EXPRESSION {
                                    std::shared_ptr<Node::PrefixExpression> prefix_expression(new Node::PrefixExpression($1));

                                    $$ = prefix_expression;
                                  }
                                  ;
OPERATION                         : "+" {
                                    $$ = std::string("+");
                                  }
                                  | "÷" {
                                    $$ = std::string("÷");
                                  }
                                  | "×" {
                                    $$ = std::string("×");
                                  }
                                  | "<" {
                                    $$ = std::string("<");
                                  }
                                  | ">" {
                                    $$ = std::string(">");
                                  }
                                  | "−" {
                                    $$ = std::string("−");
                                  }
                                  | "≤" {
                                    $$ = std::string("≤");
                                  }
                                  | "≥" {
                                    $$ = std::string("≥");
                                  }
                                  ;
POSTFIX_EXPRESSION                : PATH_EXPRESSION {
                                    std::shared_ptr<Node::PostfixExpression> postfix_expression(new Node::PostfixExpression($1));

                                    $$ = postfix_expression;
                                  }
                                  | LITERAL_EXPRESSION {
                                    std::shared_ptr<Node::PostfixExpression> postfix_expression(new Node::PostfixExpression($1));

                                    $$ = postfix_expression;
                                  }
                                  | ARRAY_EXPRESSION {
                                    std::shared_ptr<Node::PostfixExpression> postfix_expression(new Node::PostfixExpression($1));

                                    $$ = postfix_expression;
                                  }
                                  | GROUPED_EXPRESSION {
                                    std::shared_ptr<Node::PostfixExpression> postfix_expression(new Node::PostfixExpression($1));

                                    $$ = postfix_expression;
                                  }
                                  | TUPLE_EXPRESSION {
                                    std::shared_ptr<Node::PostfixExpression> postfix_expression(new Node::PostfixExpression($1));

                                    $$ = postfix_expression;
                                  }
                                  | POSTFIX_EXPRESSION OPERATION {
                                    std::shared_ptr<Node::PostfixExpression> postfix_expression(new Node::PostfixExpression($1));

                                    $$ = postfix_expression;
                                  }
                                  | CALL_EXPRESSION {
                                    std::shared_ptr<Node::PostfixExpression> postfix_expression(new Node::PostfixExpression($1));

                                    $$ = postfix_expression;
                                  }
                                  | INDEX_EXPRESSION {
                                    std::shared_ptr<Node::PostfixExpression> postfix_expression(new Node::PostfixExpression($1));

                                    $$ = postfix_expression;
                                  }
                                  ;
PATH_EXPRESSION                   : IDENTIFIER {
                                    std::shared_ptr<Node::PathExpression> path_expression(new Node::PathExpression($1));

                                    $$ = path_expression;
                                  }
                                  ;
LITERAL_EXPRESSION                : BOOLEAN_LITERAL_EXPRESSION {
                                    std::shared_ptr<Node::LiteralExpression> literal_expression(new Node::LiteralExpression($1));

                                    $$ = literal_expression;
                                  }
                                  | FLOATING_POINT_LITERAL_EXPRESSION {
                                    std::shared_ptr<Node::LiteralExpression> literal_expression(new Node::LiteralExpression($1));

                                    $$ = literal_expression;
                                  }
                                  | INTEGER_LITERAL_EXPRESSION {
                                    std::shared_ptr<Node::LiteralExpression> literal_expression(new Node::LiteralExpression($1));

                                    $$ = literal_expression;
                                  }
                                  ;
BOOLEAN_LITERAL_EXPRESSION        : "True" {
                                    std::shared_ptr<Node::BooleanLiteralExpression> boolean_literal(new Node::BooleanLiteralExpression(true));

                                    $$ = boolean_literal;
                                  }
                                  | "False" {
                                    std::shared_ptr<Node::BooleanLiteralExpression> boolean_literal(new Node::BooleanLiteralExpression(false));

                                    $$ = boolean_literal;
                                  }
                                  ;
FLOATING_POINT_LITERAL_EXPRESSION : LITERAL_FLOATING_POINT {
                                    std::shared_ptr<Node::FloatingPointLiteralExpression> floating_point_literal(new Node::FloatingPointLiteralExpression($1));

                                    $$ = floating_point_literal;
                                  }
                                  ;
INTEGER_LITERAL_EXPRESSION        : LITERAL_INTEGER {
                                    std::shared_ptr<Node::IntegerLiteralExpression> integer_literal(new Node::IntegerLiteralExpression($1));

                                    $$ = integer_literal;
                                  }
                                  ;
ARRAY_EXPRESSION                  : "[" ARRAY_EXPRESSION_ELEMENTS "]" {
                                    std::shared_ptr<Node::ArrayExpression> array_expression(new Node::ArrayExpression($2));

                                    $$ = array_expression;
                                  }
                                  ;
ARRAY_EXPRESSION_ELEMENTS         : ARRAY_EXPRESSION_ELEMENTS "," OPERATOR_EXPRESSION {
                                    std::vector<std::shared_ptr<Node::Node>> array_expression_elements = $1;

                                    array_expression_elements.push_back($3);

                                    $$ = array_expression_elements;
                                  }
                                  | OPERATOR_EXPRESSION {
                                    $$ = std::vector<std::shared_ptr<Node::Node>>();

                                    $$.push_back($1);
                                  }
                                  ;
GROUPED_EXPRESSION                : "(" OPERATOR_EXPRESSION ")" {
                                    std::shared_ptr<Node::GroupedExpression> grouped_expression(new Node::GroupedExpression($2));

                                    $$ = grouped_expression;
                                  }
                                  ;
TUPLE_EXPRESSION                  : "(" TUPLE_EXPRESSION_ELEMENTS ")" {
                                    std::shared_ptr<Node::TupleExpression> tuple_expression(new Node::TupleExpression($2));

                                    $$ = tuple_expression;
                                  }
                                  ;
TUPLE_EXPRESSION_ELEMENTS         : TUPLE_EXPRESSION_ELEMENTS "," OPERATOR_EXPRESSION {
                                    std::vector<std::shared_ptr<Node::Node>> tuple_expression_elements = $1;

                                    tuple_expression_elements.push_back($3);

                                    $$ = tuple_expression_elements;
                                  }
                                  | OPERATOR_EXPRESSION {
                                    $$ = std::vector<std::shared_ptr<Node::Node>>();

                                    $$.push_back($1);
                                  }
                                  ;
CALL_EXPRESSION                   : OPERATOR_EXPRESSION "(" CALL_EXPRESSION_ARGUMENTS ")" {
                                    std::shared_ptr<Node::CallExpression> call_expression(new Node::CallExpression($1, $3));

                                    $$ = call_expression;
                                  }
                                  ;
CALL_EXPRESSION_ARGUMENTS         : CALL_EXPRESSION_ARGUMENTS "," OPERATOR_EXPRESSION {
                                    std::vector<std::shared_ptr<Node::Node>> call_expression_arguments = $1;

                                    call_expression_arguments.push_back($3);

                                    $$ = call_expression_arguments;
                                  }
                                  | OPERATOR_EXPRESSION {
                                    $$ = std::vector<std::shared_ptr<Node::Node>>();

                                    $$.push_back($1);
                                  }
                                  ;
INDEX_EXPRESSION                  : OPERATOR_EXPRESSION "[" OPERATOR_EXPRESSION "]" {
                                    std::shared_ptr<Node::IndexExpression> index_expression(new Node::IndexExpression($1, $3));

                                    $$ = index_expression;
                                  }
                                  ;
INFIX_EXPRESSIONS                 : INFIX_EXPRESSIONS INFIX_EXPRESSION {
                                    std::vector<std::shared_ptr<Node::InfixExpression>> infix_expressions = $1;

                                    infix_expressions.push_back($2);

                                    $$ = infix_expressions;
                                  }
                                  | INFIX_EXPRESSION {
                                    $$ = std::vector<std::shared_ptr<Node::InfixExpression>>();

                                    $$.push_back($1);
                                  }
                                  ;
INFIX_EXPRESSION                  : OPERATION PREFIX_EXPRESSION {
                                    std::shared_ptr<Node::InfixExpression> infix_expression(new Node::InfixExpression($1, $2));

                                    $$ = infix_expression;
                                  }
                                  ;
ASSIGNMENT_STATEMENT              : PATTERN ":" TYPE "←" OPERATOR_EXPRESSION ";" {
                                    std::shared_ptr<Node::AssignmentStatement> assignment_statement(new Node::AssignmentStatement($1, $3, $5));

                                    $$ = assignment_statement;
                                  }
                                  ;
ITEM_STATEMENT                    : ITEM {
                                    std::shared_ptr<Node::ItemStatement> item_statement(new Node::ItemStatement($1));

                                    $$ = item_statement;
                                  }
                                  ;
ITEM                              : MODULE_ITEM {
                                    std::shared_ptr<Node::Item> item(new Node::Item($1));

                                    $$ = item;
                                  }
                                  | EXTERNAL_PACKAGE_ITEM {
                                    std::shared_ptr<Node::Item> item(new Node::Item($1));

                                    $$ = item;
                                  }
                                  | CONSTANT_ITEM {
                                    std::shared_ptr<Node::Item> item(new Node::Item($1));

                                    $$ = item;
                                  }
                                  | TYPE_ITEM {
                                    std::shared_ptr<Node::Item> item(new Node::Item($1));

                                    $$ = item;
                                  }
                                  | SUBROUTINE_ITEM {
                                    std::shared_ptr<Node::Item> item(new Node::Item($1));

                                    $$ = item;
                                  }
                                  ;
MODULE_ITEM                       : "module" IDENTIFIER "{" ITEMS "}" ";" {
                                    std::shared_ptr<Node::ModuleItem> module_item(new Node::ModuleItem($2, $4));

                                    $$ = module_item;
                                  }
                                  | "module" IDENTIFIER ";" {
                                    std::shared_ptr<Node::ModuleItem> module_item(new Node::ModuleItem($2));

                                    $$ = module_item;
                                  }
                                  ;
ITEMS                             : ITEMS ITEM {
                                    std::vector<std::shared_ptr<Node::Item>> items = $1;

                                    items.push_back($2);

                                    $$ = items;
                                  }
                                  | ITEM {
                                    $$ = std::vector<std::shared_ptr<Node::Item>>();

                                    $$.push_back($1);
                                  }
                                  ;
EXTERNAL_PACKAGE_ITEM             : "external" "package" IDENTIFIER "as" IDENTIFIER ";" {
                                    std::shared_ptr<Node::ExternalPackageItem> external_package_item(new Node::ExternalPackageItem($3, $5));

                                    $$ = external_package_item;
                                  }
                                  | "external" "package" IDENTIFIER ";" {
                                    std::shared_ptr<Node::ExternalPackageItem> external_package_item(new Node::ExternalPackageItem($3));

                                    $$ = external_package_item;
                                  }
                                  ;
CONSTANT_ITEM                     : "constant" IDENTIFIER ":" TYPE "←" OPERATOR_EXPRESSION ";" {
                                    std::shared_ptr<Node::ConstantItem> constant_item(new Node::ConstantItem($2, $4, $6));

                                    $$ = constant_item;
                                  }
                                  ;
TYPE_ITEM                         : "type" IDENTIFIER "←" TYPE ";" {
                                    std::shared_ptr<Node::TypeItem> type_item(new Node::TypeItem($2, $4));

                                    $$ = type_item;
                                  }
                                  ;
SUBROUTINE_ITEM                   : "subroutine" IDENTIFIER FUNCTION_TYPE BLOCK_STATEMENT {
                                    std::shared_ptr<Node::SubroutineItem> subroutine_item(new Node::SubroutineItem($2, $3, $4));

                                    $$ = subroutine_item;
                                  }
                                  ;
CONDITIONAL_STATEMENT             : "if" OPERATOR_EXPRESSION BLOCK_STATEMENT "else" BLOCK_STATEMENT ";" {
                                    std::shared_ptr<Node::ConditionalStatement> conditional_statement(new Node::ConditionalStatement($2, $3, $5));

                                    $$ = conditional_statement;
                                  }
                                  | "if" OPERATOR_EXPRESSION BLOCK_STATEMENT ";" {
                                    std::shared_ptr<Node::ConditionalStatement> conditional_statement(new Node::ConditionalStatement($2, $3));

                                    $$ = conditional_statement;
                                  }
                                  ;
RETURN_STATEMENT                  : "return" OPERATOR_EXPRESSION ";" {
                                    std::shared_ptr<Node::ReturnStatement> return_statement(new Node::ReturnStatement($2));

                                    $$ = return_statement;
                                  }
                                  | "return" ";" {
                                    std::shared_ptr<Node::ReturnStatement> return_statement(new Node::ReturnStatement());

                                    $$ = return_statement;
                                  }
                                  ;
BLOCK_STATEMENT                   : "{" STATEMENTS "}" {
                                    std::shared_ptr<Node::BlockStatement> block_statement(new Node::BlockStatement($2));

                                    $$ = block_statement;
                                  }
                                  ;
PATTERN                           : IDENTIFIER_PATTERN {
                                    std::shared_ptr<Node::Pattern> pattern(new Node::Pattern($1));

                                    $$ = pattern;
                                  }
                                  | WILDCARD_PATTERN {
                                    std::shared_ptr<Node::Pattern> pattern(new Node::Pattern($1));

                                    $$ = pattern;
                                  }
                                  | TUPLE_PATTERN {
                                    std::shared_ptr<Node::Pattern> pattern(new Node::Pattern($1));

                                    $$ = pattern;
                                  }
                                  | REFERENCE_PATTERN {
                                    std::shared_ptr<Node::Pattern> pattern(new Node::Pattern($1));

                                    $$ = pattern;
                                  }
                                  ;
IDENTIFIER_PATTERN                : IDENTIFIER {
                                    std::shared_ptr<Node::IdentifierPattern> identifier_pattern(new Node::IdentifierPattern($1));

                                    $$ = identifier_pattern;
                                  }
                                  ;
WILDCARD_PATTERN                  : "_" {
                                    std::shared_ptr<Node::WildcardPattern> wildcard_pattern(new Node::WildcardPattern());

                                    $$ = wildcard_pattern;
                                  }
                                  ;
TUPLE_PATTERN                     : "(" TUPLE_PATTERN_ITEMS ")" {
                                    std::shared_ptr<Node::TuplePattern> tuple_pattern(new Node::TuplePattern($2));

                                    $$ = tuple_pattern;
                                  }
                                  ;
TUPLE_PATTERN_ITEMS               : TUPLE_PATTERN_ITEMS "," PATTERN {
                                    std::vector<std::shared_ptr<Node::Pattern>> patterns = $1;

                                    patterns.push_back($3);

                                    $$ = patterns;
                                  }
                                  | PATTERN {
                                    $$ = std::vector<std::shared_ptr<Node::Pattern>>();

                                    $$.push_back($1);
                                  }
                                  ;
REFERENCE_PATTERN                 : "reference" PATTERN {
                                    std::shared_ptr<Node::ReferencePattern> reference_pattern(new Node::ReferencePattern($2));

                                    $$ = reference_pattern;
                                  }
                                  ;
TYPE                              : FUNCTION_TYPE {
                                    std::shared_ptr<Node::Type> type(new Node::Type($1));

                                    $$ = type;
                                  }
                                  | ARRAY_TYPE {
                                    std::shared_ptr<Node::Type> type(new Node::Type($1));

                                    $$ = type;
                                  }
                                  | BOOLEAN_TYPE {
                                    std::shared_ptr<Node::Type> type(new Node::Type($1));

                                    $$ = type;
                                  }
                                  | FLOATING_POINT_TYPE {
                                    std::shared_ptr<Node::Type> type(new Node::Type($1));

                                    $$ = type;
                                  }
                                  | INTEGER_TYPE {
                                    std::shared_ptr<Node::Type> type(new Node::Type($1));

                                    $$ = type;
                                  }
                                  | SIZE_TYPE {
                                    std::shared_ptr<Node::Type> type(new Node::Type($1));

                                    $$ = type;
                                  }
                                  | REFERENCE_TYPE {
                                    std::shared_ptr<Node::Type> type(new Node::Type($1));

                                    $$ = type;
                                  }
                                  | SLICE_TYPE {
                                    std::shared_ptr<Node::Type> type(new Node::Type($1));

                                    $$ = type;
                                  }
                                  ;
FUNCTION_TYPE                     : "(" FUNCTION_TYPE_PARAMETERS ")" "→" TYPE {
                                    std::shared_ptr<Node::FunctionType> function_type(new Node::FunctionType($2, $5));

                                    $$ = function_type;
                                  }
                                  ;
FUNCTION_TYPE_PARAMETERS          : FUNCTION_TYPE_PARAMETERS "," FUNCTION_TYPE_PARAMETER {
                                    std::vector<std::shared_ptr<Node::Parameter>> items = $1;

                                    items.push_back($3);

                                    $$ = items;
                                  }
                                  | FUNCTION_TYPE_PARAMETER {
                                    $$ = std::vector<std::shared_ptr<Node::Parameter>>();

                                    $$.push_back($1);
                                  }
                                  ;
FUNCTION_TYPE_PARAMETER           : IDENTIFIER ":" TYPE {
                                    std::shared_ptr<Node::Parameter> function_type_parameter(new Node::Parameter($1, $3));

                                    $$ = function_type_parameter;
                                  }
                                  ;
ARRAY_TYPE                        : "[" TYPE "×" ANONYMOUS_CONSTANT "]" {
                                    std::shared_ptr<Node::ArrayType> array_type(new Node::ArrayType($2, $4));

                                    $$ = array_type;
                                  }
                                  ;
ANONYMOUS_CONSTANT                : OPERATOR_EXPRESSION {
                                    std::shared_ptr<Node::AnonymousConstant> anonymous_constant(new Node::AnonymousConstant($1));

                                    $$ = anonymous_constant;
                                  }
                                  ;
BOOLEAN_TYPE                      : "Boolean" {
                                    std::shared_ptr<Node::BooleanType> boolean_type(new Node::BooleanType());

                                    $$ = boolean_type;
                                  }
                                  ;
FLOATING_POINT_TYPE               : "32-bit" "Floating-point" {
                                    std::shared_ptr<Node::FloatingPointType> floating_point_type(new Node::FloatingPointType());

                                    $$ = floating_point_type;
                                  }
                                  | "64-bit" "Floating-point" {
                                    std::shared_ptr<Node::FloatingPointType> floating_point_type(new Node::FloatingPointType());

                                    $$ = floating_point_type;
                                  }
                                  ;
INTEGER_TYPE                      : "unsigned"  "8-bit" "Integer" {
                                    std::shared_ptr<Node::IntegerType> integer_type(new Node::IntegerType());

                                    $$ = integer_type;
                                  }
                                  |             "8-bit" "Integer" {
                                    std::shared_ptr<Node::IntegerType> integer_type(new Node::IntegerType());

                                    $$ = integer_type;
                                  }
                                  | "unsigned" "16-bit" "Integer" {
                                    std::shared_ptr<Node::IntegerType> integer_type(new Node::IntegerType());

                                    $$ = integer_type;
                                  }
                                  |            "16-bit" "Integer" {
                                    std::shared_ptr<Node::IntegerType> integer_type(new Node::IntegerType());

                                    $$ = integer_type;
                                  }
                                  | "unsigned" "32-bit" "Integer" {
                                    std::shared_ptr<Node::IntegerType> integer_type(new Node::IntegerType());

                                    $$ = integer_type;
                                  }
                                  |            "32-bit" "Integer" {
                                    std::shared_ptr<Node::IntegerType> integer_type(new Node::IntegerType());

                                    $$ = integer_type;
                                  }
                                  | "unsigned" "64-bit" "Integer" {
                                    std::shared_ptr<Node::IntegerType> integer_type(new Node::IntegerType());

                                    $$ = integer_type;
                                  }
                                  |            "64-bit" "Integer" {
                                    std::shared_ptr<Node::IntegerType> integer_type(new Node::IntegerType());

                                    $$ = integer_type;
                                  }
                                  ;
SIZE_TYPE                         : "unsigned"          "Size" {
                                    std::shared_ptr<Node::SizeType> size_type(new Node::SizeType());

                                    $$ = size_type;
                                  }
                                  |                     "Size"  {
                                    std::shared_ptr<Node::SizeType> size_type(new Node::SizeType());

                                    $$ = size_type;
                                  }
                                  ;
REFERENCE_TYPE                    : "reference" TYPE {
                                    std::shared_ptr<Node::ReferenceType> reference_type(new Node::ReferenceType($2));

                                    $$ = reference_type;
                                  }
                                  ;
SLICE_TYPE                        : "[" TYPE "]" {
                                    std::shared_ptr<Node::SliceType> slice_type(new Node::SliceType($2));

                                    $$ = slice_type;
                                  }
                                  ;

%%

void yy::parser::error(const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
