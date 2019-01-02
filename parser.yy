%skeleton "lalr1.cc" /* -*- C++ -*- */

%require "3.2"

%defines

%define api.token.constructor

%define api.value.type variant

%define parse.assert

%code requires {
  #include <string>

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
    #include "ox.hh"
}

%define api.token.prefix {TOK_}

%token END 0 "end of file";

%token
  PLUS_SIGN                         "+"
  MULTIPLICATION_SIGN               "×"
  DIVISION_SIGN                     "÷"
  MINUS_SIGN                        "−"
;

%token
  COLON                             ":"
  SEMICOLON                         ";"
  HORIZONTAL_ELLIPSIS               "…"
;

%token
  LEFTWARDS_ARROW                   "←"
  RIGHTWARDS_ARROW                  "→"
;

%token
  GREEK_SMALL_LETTER_LAMBDA         "λ"
;

%token
  LEFT_PARENTHESIS                  "("
  RIGHT_PARENTHESIS                 ")"
  LEFT_SQUARE_BRACKET               "["
  RIGHT_SQUARE_BRACKET              "]"
  LEFT_CURLY_BRACKET                "{"
  RIGHT_CURLY_BRACKET               "}"
  MATHEMATICAL_LEFT_ANGLE_BRACKET   "⟨"
  MATHEMATICAL_RIGHT_ANGLE_BRACKET  "⟩"
;

%token
  LESS_THAN_SIGN                    "<"
  EQUALS_SIGN                       "="
  GREATER_THAN_SIGN                 ">"
  NOT_EQUAL_TO                      "≠"
  LESS_THAN_OR_EQUAL_TO             "≤"
  GREATER_THAN_OR_EQUAL_TO          "≥"
;

%token
  NOT_AND                           "¬" 
  LOGICAL_AND                       "∧" 
  LOGICAL_OR                        "∨" 
  XOR                               "⊻"
;

%token
  EIGHT_BIT_KEYWORD                 "8-bit"
  SIXTEEN_BIT_KEYWORD               "16-bit"
  THIRTY_TWO_BIT_KEYWORD            "32-bit"
  SIXTY_FOUR_BIT_KEYWORD            "64-bit"
;

%token
  BOOLEAN_KEYWORD                   "Boolean"
  INTEGER_KEYWORD                   "Integer"
  FLOATING_POINT_KEYWORD            "Floating-point"
;

%token
  AS_KEYWORD                        "as"
  BREAK_KEYWORD                     "break"
  CASE_KEYWORD                      "case"
  CLOSURE_KEYWORD                   "closure"
  CONSTANT_KEYWORD                  "constant"
  CONTINUE_KEYWORD                  "continue"
  DEFAULT_KEYWORD                   "default"
  ELSE_KEYWORD                      "else"  
  ENUMERATED_KEYWORD                "enumerated"
  FOR_KEYWORD                       "for"
  GOTO_KEYWORD                      "goto"
  IF_KEYWORD                        "if"
  IMMUTABLE_KEYWORD                 "immutable"
  INFIX_KEYWORD                     "infix"
  LABEL_KEYWORD                     "label"
  MODULE_KEYWORD                    "module"
  MUTABLE_KEYWORD                   "mutable"
  OPERATOR_KEYWORD                  "operator"
  POSTFIX_KEYWORD                   "postfix"
  PREFIX_KEYWORD                    "prefix"
  RECORD_KEYWORD                    "record"
  REFERENCE_KEYWORD                 "reference"
  RETURN_KEYWORD                    "return"
  SUBROUTINE_KEYWORD                "subroutine"
  SWITCH_KEYWORD                    "switch"
  TYPE_KEYWORD                      "type"
  UNION_KEYWORD                     "union"
  UNSIGNED_KEYWORD                  "unsigned"
  WHILE_KEYWORD                     "while"
;

%token <std::string> IDENTIFIER

%token <int> NUMBER "number"

%type <int> EXPRESSION
%type <int> GROUPED_EXPRESSION
%type <int> OPERATOR_EXPRESSION
%type <int> INFIX_OPERATOR_EXPRESSION
%type <int> ARITHMETIC_INFIX_OPERATOR_EXPRESSION
%type <int> ASSIGNMENT_INFIX_OPERATOR_EXPRESSION
%type <int> COMPARISON_INFIX_OPERATOR_EXPRESSION
%type <int> LOGICAL_INFIX_OPERATOR_EXPRESSION
%type <int> TYPE_CONVERSION_INFIX_OPERATOR_EXPRESSION
%type <int> CONDITIONAL_EXPRESSION

%printer {
    yyo << $$;
} <*>;

%%

%start UNIT;

%left "+" "−";
%left "×" "÷";

TYPE                                      : PRIMITIVE_TYPE
                                          ;
PRIMITIVE_TYPE                            : FLOATING_POINT_PRIMITIVE_TYPE
                                          | INTEGER_PRIMITIVE_TYPE
                                          ;
FLOATING_POINT_SIZE                       : "16-bit"
                                          | "32-bit"
                                          ;
FLOATING_POINT_PRIMITIVE_TYPE             : FLOATING_POINT_SIZE "Floating-point"
                                          ;
INTEGER_SIZE                              :  "8-bit"
                                          | "16-bit"
                                          | "32-bit"
                                          | "64-bit"
                                          ;
INTEGER_PRIMITIVE_TYPE                    : INTEGER_SIZE "Integer"
                                          ;
UNIT                                      : EXPRESSIONS EXPRESSION {
                                            compiler.result = $2;
                                          };
EXPRESSIONS                               : %empty
                                          | EXPRESSIONS EXPRESSION
                                          ;
EXPRESSION                                : "number"
                                          | IDENTIFIER {
                                            $$ = compiler.variables[$1];
                                          }
                                          | OPERATOR_EXPRESSION
                                          | CONDITIONAL_EXPRESSION
                                          | GROUPED_EXPRESSION
                                          ;
CONDITIONAL_EXPRESSION                    : "if" EXPRESSION "{" EXPRESSIONS "}" "else" "{" EXPRESSIONS "}" {
                                            $$ = 1;
                                          }
                                          | "if" EXPRESSION "{" EXPRESSIONS "}" {
                                            $$ = 1;
                                          }
                                          | "switch" EXPRESSION "{" EXPRESSIONS "}" {
                                            $$ = 1;
                                          }
                                          ;
GROUPED_EXPRESSION                        : "(" EXPRESSION ")" {
                                            $$ = $2;
                                          }
OPERATOR_EXPRESSION                       : INFIX_OPERATOR_EXPRESSION
                                          ;
INFIX_OPERATOR_EXPRESSION                 : ARITHMETIC_INFIX_OPERATOR_EXPRESSION
                                          | ASSIGNMENT_INFIX_OPERATOR_EXPRESSION
                                          | COMPARISON_INFIX_OPERATOR_EXPRESSION
                                          | LOGICAL_INFIX_OPERATOR_EXPRESSION
                                          | TYPE_CONVERSION_INFIX_OPERATOR_EXPRESSION
                                          ;
ARITHMETIC_INFIX_OPERATOR_EXPRESSION      : EXPRESSION "+" EXPRESSION {
                                            $$ = $1 + $3;
                                          }
                                          | EXPRESSION "−" EXPRESSION {
                                            $$ = $1 - $3;
                                          }
                                          | EXPRESSION "×" EXPRESSION {
                                            $$ = $1 * $3;
                                          }
                                          | EXPRESSION "÷" EXPRESSION {
                                            $$ = $1 / $3;
                                          }
                                          ;
ASSIGNMENT_INFIX_OPERATOR_EXPRESSION      : IDENTIFIER "←" EXPRESSION {
                                            compiler.variables[$1] = $3;
                                          }
COMPARISON_INFIX_OPERATOR_EXPRESSION      : EXPRESSION "<" EXPRESSION {
                                            $$ = 1;
                                          }
                                          | EXPRESSION "=" EXPRESSION {
                                            $$ = 1;
                                          }
                                          | EXPRESSION ">" EXPRESSION {
                                            $$ = 1;
                                          }
                                          | EXPRESSION "≠" EXPRESSION {
                                            $$ = 1;
                                          }
                                          | EXPRESSION "≤" EXPRESSION {
                                            $$ = 1;
                                          }
                                          | EXPRESSION "≥" EXPRESSION {
                                            $$ = 1;
                                          }
                                          ;
LOGICAL_INFIX_OPERATOR_EXPRESSION         : EXPRESSION "∧" EXPRESSION {
                                            $$ = 1;
                                          }
                                          | EXPRESSION "∨" EXPRESSION {
                                            $$ = 1;
                                          }
                                          | EXPRESSION "⊻" EXPRESSION {
                                            $$ = 1;
                                          }
                                          ;
TYPE_CONVERSION_INFIX_OPERATOR_EXPRESSION : EXPRESSION "as" TYPE {
                                            $$ = 1;
                                          }
                                          ;

%%

void yy::parser::error(const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
