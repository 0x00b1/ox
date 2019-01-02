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
  LEFTWARDS_ARROW                   "←"
  RIGHTWARDS_ARROW                  "→"
  COLON                             ":"
  SEMICOLON                         ";"
  HORIZONTAL_ELLIPSIS               "…"
  LEFT_PARENTHESIS                  "("
  RIGHT_PARENTHESIS                 ")"
  LEFT_SQUARE_BRACKET               "["
  RIGHT_SQUARE_BRACKET              "]"
  LEFT_CURLY_BRACKET                "{"
  RIGHT_CURLY_BRACKET               "}"
  MATHEMATICAL_LEFT_ANGLE_BRACKET   "⟨"
  MATHEMATICAL_RIGHT_ANGLE_BRACKET  "⟩"
  MULTIPLICATION_SIGN               "×"
  MINUS_SIGN                        "−"
  DIVISION_SIGN                     "÷"
  PLUS_SIGN                         "+"
;

%token
  SIXTEEN_BIT_KEYWORD               "16-bit"
  THIRTY_TWO_BIT_KEYWORD            "32-bit"
  SIXTY_FOUR_BIT_KEYWORD            "64-bit"
  EIGHT_BIT_KEYWORD                 "8-bit"
  BOOLEAN_KEYWORD                   "BooleanLiteral"
  BREAK_KEYWORD                     "break"
  CASE_KEYWORD                      "case"
  CLOSURE_KEYWORD                   "closure"
  CONSTANT_KEYWORD                  "constant"
  CONTINUE_KEYWORD                  "continue"
  DEFAULT_KEYWORD                   "default"
  ELSE_KEYWORD                      "else"
  ENUMERATED_KEYWORD                "enumerated"
  FLOATING_POINT_KEYWORD            "Floating-point"
  FOR_KEYWORD                       "for"
  GOTO_KEYWORD                      "goto"
  IF_KEYWORD                        "if"
  IMMUTABLE_KEYWORD                 "immutable"
  INFIX_KEYWORD                     "infix"
  INTEGER_KEYWORD                   "IntegerLiteral"
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

%token <std::string> IDENTIFIER "identifier"

%token <int> NUMBER "number"

%type  <int> expression

%printer {
    yyo << $$;
} <*>;

%%

%start unit;

unit        : assignments expression {
                compiler.result = $2;
            };
assignments : %empty {

            }
            | assignments assignment {

            }
            ;
type        : "8-bit" "IntegerLiteral"
            | "16-bit" "IntegerLiteral"
            | "32-bit" "IntegerLiteral"
            | "64-bit" "IntegerLiteral"
            | "16-bit" "Floating-point"
            | "32-bit" "Floating-point"
            ;
assignment  : "constant" "identifier" ":" type "←" expression ";" {
                compiler.variables[$2] = $6;
            }
            ;

%left "+" "−";
%left "×" "÷";

expression  : "number"
            | "identifier"  {
                $$ = compiler.variables[$1];
            }
            | expression "+" expression   {
                $$ = $1 + $3;
            }
            | expression "−" expression   {
                $$ = $1 - $3;
            }
            | expression "×" expression   {
                $$ = $1 * $3;
            }
            | expression "÷" expression   {
                $$ = $1 / $3;
            }
            | "(" expression ")"   {
                $$ = $2;
            }
            ;

%%

void yy::parser::error(const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
