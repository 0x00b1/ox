%skeleton "lalr1.cc" /* -*- C++ -*- */

%require "3.2"

%defines

%define api.token.constructor

%define api.value.type variant

%define parse.assert

%code requires {
  #include <string>

  #include "syntax/node/Node.hh"

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
    #include "syntax/node/Node.hh"
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

%printer {
    // FIXME:
    //yyo << $$;
    yyo << typeid($$).name();
} <*>;

%%

%start UNIT;

UNIT                        : STATEMENTS
                            ;
STATEMENTS                  : STATEMENT
                            | STATEMENTS STATEMENT
                            ;
STATEMENT                   : BLOCK_STATEMENT
                            | CONDITIONAL_STATEMENT
                            | DECLARATION_STATEMENT
                            | EXPRESSION_STATEMENT
                            | RETURN_STATEMENT
                            ;
BLOCK_STATEMENT             : "{" STATEMENTS "}" 
                            ;
CONDITIONAL_STATEMENT       : "if" EXPRESSION BLOCK_STATEMENT
                            | "if" EXPRESSION BLOCK_STATEMENT "else" BLOCK_STATEMENT
                            ;
DECLARATION_STATEMENT       : DECLARATION ";"
                            ;
DECLARATION                 : SUBROUTINE_DECLARATION
                            | VARIABLE_DECLARATION
                            ;
SUBROUTINE_DECLARATION      : "subroutine" IDENTIFIER FUNCTION_TYPE
                            | "subroutine" IDENTIFIER FUNCTION_TYPE BLOCK_STATEMENT
                            ;
VARIABLE_DECLARATION        : IDENTIFIER "←" EXPRESSION
                            | IDENTIFIER ":" TYPE "←" EXPRESSION
                            | "constant" IDENTIFIER "←" EXPRESSION
                            | "constant" IDENTIFIER ":" TYPE "←" EXPRESSION
                            ;
EXPRESSION_STATEMENT        : EXPRESSION ";"
                            ;
EXPRESSION                  : "(" EXPRESSION ")"
                            | ARRAY_EXPRESSION
                            | CALL_EXPRESSION
                            | INDEX_EXPRESSION
                            | LITERAL_EXPRESSION
                            | PATH_EXPRESSION
                            ;
ARRAY_EXPRESSION            : "[" ELEMENTS "]"
                            ;
ELEMENTS                    : ELEMENT
                            | ELEMENTS "," ELEMENT
                            ;
ELEMENT                     : EXPRESSION
                            ;
CALL_EXPRESSION             : EXPRESSION "(" ARGUMENTS ")"
                            ;
ARGUMENTS                   : ARGUMENT
                            | ARGUMENTS "," ARGUMENT
                            ;
ARGUMENT                    : EXPRESSION
                            ;
INDEX_EXPRESSION            : EXPRESSION "[" EXPRESSION "]"
                            ;
LITERAL_EXPRESSION          : BOOLEAN_EXPRESSION
                            | FLOATING_POINT_EXPRESSION
                            | INTEGER_EXPRESSION
                            ;
BOOLEAN_EXPRESSION          : "True" 
                            | "False"
                            ;
FLOATING_POINT_EXPRESSION   : LITERAL_FLOATING_POINT
                            ;
INTEGER_EXPRESSION          : LITERAL_INTEGER
                            ;
PATH_EXPRESSION             : IDENTIFIER
                            ;
RETURN_STATEMENT            : "return" ";"
                            | "return" EXPRESSION ";"
                            ;
TYPE                        : ARRAY_TYPE
                            | BOOLEAN_TYPE
                            | FLOATING_POINT_TYPE
                            | FUNCTION_TYPE
                            | INTEGER_TYPE
                            | REFERENCE_TYPE
                            | SLICE_TYPE
                            ;
ARRAY_TYPE                  : "[" TYPE "×" SIZES "]" 
                            ;
SIZES                       : EXPRESSION
                            | SIZES "×" EXPRESSION
                            ;
BOOLEAN_TYPE                : "Boolean" 
                            ;
FLOATING_POINT_TYPE         : "32-bit" "Floating-point" 
                            | "64-bit" "Floating-point" 
                            ;
FUNCTION_TYPE               : "(" PARAMETERS ")" "→" TYPE
                            ;
PARAMETERS                  : 
                            | PARAMETER
                            | PARAMETERS "," PARAMETER
                            ;
PARAMETER                   : TYPE
                            | IDENTIFIER ":" TYPE
                            ;
INTEGER_TYPE                : "unsigned"  "8-bit" "Integer"
                            | "unsigned" "16-bit" "Integer"
                            | "unsigned" "32-bit" "Integer"
                            | "unsigned" "64-bit" "Integer"
                            |             "8-bit" "Integer"
                            |            "16-bit" "Integer"
                            |            "32-bit" "Integer"
                            |            "64-bit" "Integer"
                            | "unsigned" "Size"
                            |            "Size" 
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
