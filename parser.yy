%skeleton "lalr1.cc" /* -*- C++ -*- */

%require "3.2"

%defines

%define api.token.constructor

%define api.value.type variant

%define parse.assert

%code requires {
  #include <string>

  #include "ox.hh"

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
  COMMA                             ","
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
  PRIME                             "′"
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
  NOT_EQUAL_TO
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
  EIGHT_BIT_KEYWORD                  "8-bit"
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
  COROUTINE_KEYWORD                 "coroutine"
  DEFAULT_KEYWORD                   "default"
  ELSE_KEYWORD                      "else"  
  ENUMERATED_KEYWORD                "enumerated"
  FALSE_KEYWORD                     "false"
  FOR_KEYWORD                       "for"
  GOTO_KEYWORD                      "goto"
  IF_KEYWORD                        "if"
  IMMUTABLE_KEYWORD                 "immutable"
  IN_KEYWORD                        "in"
  INFIX_KEYWORD                     "infix"
  IS_KEYWORD                        "is"
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
  TRUE_KEYWORD                      "true"
  TYPE_KEYWORD                      "type"
  UNION_KEYWORD                     "union"
  UNSIGNED_KEYWORD                  "unsigned"
  WHILE_KEYWORD                     "while"
;

%token <std::string> IDENTIFIER

%token <std::string> BOOLEAN
%token <std::string> INTEGER 
%token <std::string> FLOATING_POINT 

%type <AST::Root*> ROOT

%printer {
    yyo << $$;
} <*>;

%%

%start ROOT;

%right "←";

%left "⊻";
%left "∨";
%left "∧";
%left "<" ">" "≤" "≥" "=" "≠";
%left "+" "−";
%left "×" "÷";
%left "as" ":";
%left "(" ")";
%left "[" "]" "⟨" "⟩";

ROOT                                      : MODULE_DECLARATIONS {
                                            $$ = new AST::Root();
                                          }
                                          ;

MODULE_DECLARATIONS                       : MODULE_DECLARATIONS MODULE_DECLARATION 
                                          | MODULE_DECLARATION
                                          | %empty
                                          ;

MODULE_DECLARATION                        : "module" IDENTIFIER "{" DECLARATIONS "}" ";"
                                          ;

DECLARATIONS                              : DECLARATIONS DECLARATION
                                          | DECLARATION
                                          | %empty
                                          ;

DECLARATION                               : CONSTANT_DECLARATION
                                          | ENUMERATED_DECLARATION
                                          | MODULE_DECLARATION
                                          | RECORD_DECLARATION
                                          | SUBROUTINE_DECLARATION
                                          | TYPE_DECLARATION
                                          | UNION_DECLARATION
                                          ;

CONSTANT_DECLARATION                      : "constant" IDENTIFIER ":" TYPE "←" EXPRESSIONS ";"
                                          ;

TYPE                                      : PRIMITIVE_TYPE
                                          | COMPOSITE_TYPE
                                          | PATH_TYPE
                                          | REFERENCE_TYPE
                                          ;

PRIMITIVE_TYPE                            : "Boolean"
                                          | FLOATING_POINT_PRIMITIVE_TYPE_SIZE "Floating-point"
                                          | INTEGER_PRIMITIVE_TYPE_SIZE "Integer"
                                          ;

FLOATING_POINT_PRIMITIVE_TYPE_SIZE        : "16-bit"
                                          | "32-bit"
                                          ;

INTEGER_PRIMITIVE_TYPE_SIZE               :  "8-bit"
                                          | "16-bit"
                                          | "32-bit"
                                          | "64-bit"
                                          ;

COMPOSITE_TYPE                            : "[" ARRAY_COMPOSITE_TYPE_ITEM "×" TYPE "]"
                                          | "⟨" TUPLE_COMPOSITE_TYPE_ITEM "⟩"
                                          ;

ARRAY_COMPOSITE_TYPE_ITEM                 : ARRAY_COMPOSITE_TYPE_ITEM "×" INTEGER
                                          | INTEGER
                                          ;

TUPLE_COMPOSITE_TYPE_ITEM                 : TUPLE_COMPOSITE_TYPE_ITEM "×" TYPE
                                          | TYPE
                                          ;

PATH_TYPE                                 : PATH_TYPE "::" IDENTIFIER
                                          | IDENTIFIER
                                          ;

REFERENCE_TYPE                            : "reference" TYPE
                                          ;

EXPRESSIONS                               : EXPRESSIONS EXPRESSION
                                          | EXPRESSION
                                          ;

EXPRESSION                                : "(" EXPRESSION ")"
                                          | BREAK_EXPRESSION
                                          | CALL_EXPRESSION
                                          | CLOSURE_EXPRESSION
                                          | CONDITIONAL_EXPRESSION
                                          | CONTINUE_EXPRESSION
                                          | FOR_EXPRESSION
                                          | IDENTIFIER
                                          | LITERAL_EXPRESSION
                                          | OPERATOR_EXPRESSION
                                          | RANGE_EXPRESSION
                                          | RECORD_EXPRESSION
                                          | RETURN_EXPRESSION
                                          | SUBSCRIPT_EXPRESSION
                                          | WHILE_EXPRESSION
                                          ;

BREAK_EXPRESSION                          : "break" ";"
                                          | "break" EXPRESSIONS ";"
                                          ;

CALL_EXPRESSION                           : EXPRESSION "(" CALL_EXPRESSION_PARAMETERS ")"
                                          ;

CALL_EXPRESSION_PARAMETERS                : CALL_EXPRESSION_PARAMETERS "," EXPRESSIONS
                                          | EXPRESSIONS
                                          | %empty
                                          ;

CLOSURE_EXPRESSION                        : "λ" "(" PARAMETERS ")" "→" TYPE BLOCK_EXPRESSION
                                          ;

PARAMETERS                                : PARAMETERS "," PARAMETER
                                          | PARAMETER
                                          | %empty
                                          ;

PARAMETER                                 : IDENTIFIER ":" TYPE
                                          ;

BLOCK_EXPRESSION                          : "{" EXPRESSIONS "}"
                                          ;

CONDITIONAL_EXPRESSION                    : "if" EXPRESSION BLOCK_EXPRESSION
                                          | "if" EXPRESSION BLOCK_EXPRESSION "else" BLOCK_EXPRESSION
                                          | "switch" EXPRESSION BLOCK_EXPRESSION ";"
                                          ;

CONTINUE_EXPRESSION                       : "continue" EXPRESSION ";"
                                          | "continue" ";"
                                          ;

FOR_EXPRESSION                            : "for" IDENTIFIER "in" EXPRESSION BLOCK_EXPRESSION
                                          ;

LITERAL_EXPRESSION                        : BOOLEAN
                                          | INTEGER
                                          | FLOATING_POINT
                                          ;

OPERATOR_EXPRESSION                       : INFIX_OPERATOR_EXPRESSION
                                          ;

INFIX_OPERATOR_EXPRESSION                 : ASSIGNMENT_INFIX_OPERATOR_EXPRESSION
                                          | TYPE_CONVERSION_INFIX_OPERATOR_EXPRESSION
                                          | EXPRESSION "+" EXPRESSION
                                          | EXPRESSION "−" EXPRESSION
                                          | EXPRESSION "×" EXPRESSION
                                          | EXPRESSION "÷" EXPRESSION
                                          | EXPRESSION "<" EXPRESSION
                                          | EXPRESSION "=" EXPRESSION
                                          | EXPRESSION ">" EXPRESSION
                                          | EXPRESSION "≠" EXPRESSION
                                          | EXPRESSION "≤" EXPRESSION
                                          | EXPRESSION "≥" EXPRESSION
                                          | EXPRESSION "∧" EXPRESSION
                                          | EXPRESSION "∨" EXPRESSION
                                          | EXPRESSION "⊻" EXPRESSION
                                          ;

ASSIGNMENT_INFIX_OPERATOR_EXPRESSION      : IDENTIFIER "←" EXPRESSION
                                          ;

TYPE_CONVERSION_INFIX_OPERATOR_EXPRESSION : EXPRESSION "as" TYPE
                                          ;

RANGE_EXPRESSION                          : EXPRESSION "," "…" EXPRESSION
                                          | EXPRESSION "," EXPRESSION "," "…" EXPRESSION
                                          ;

RECORD_EXPRESSION                         : PATH_TYPE "{" RECORD_EXPRESSION_FIELDS "}"
                                          ;

RECORD_EXPRESSION_FIELDS                  : RECORD_EXPRESSION_FIELDS "," RECORD_EXPRESSION_FIELD
                                          | RECORD_EXPRESSION_FIELD
                                          | %empty
                                          ;

RECORD_EXPRESSION_FIELD                   : IDENTIFIER ":" EXPRESSION
                                          ;

RETURN_EXPRESSION                         : "return" ";"
                                          | "return" EXPRESSION ";"
                                          ;

SUBSCRIPT_EXPRESSION                      : EXPRESSION "[" INDEX_EXPRESSIONS "]"
                                          | EXPRESSION "⟨" INDEX_EXPRESSIONS "⟩"
                                          ;

INDEX_EXPRESSIONS                         : INDEX_EXPRESSIONS "," EXPRESSION
                                          | EXPRESSION
                                          ;

WHILE_EXPRESSION                          : "while" EXPRESSION BLOCK_EXPRESSION
                                          ;

ENUMERATED_DECLARATION                    : "enumerated" IDENTIFIER "{" ENUMERATED_DECLARATION_ITEMS "}" ";"
                                          ;

ENUMERATED_DECLARATION_ITEMS              : ENUMERATED_DECLARATION_ITEMS "," IDENTIFIER
                                          | IDENTIFIER
                                          ;

RECORD_DECLARATION                        : "record" IDENTIFIER ";"
                                          | "record" IDENTIFIER "{" FIELDS "}" ";"
                                          ;

FIELDS                                    : FIELDS "," TYPED_IDENTIFIER
                                          | TYPED_IDENTIFIER
                                          | %empty
                                          ;

TYPED_IDENTIFIER                          : IDENTIFIER ":" TYPE
                                          ;

SUBROUTINE_DECLARATION                    : "subroutine" IDENTIFIER "(" PARAMETERS ")" "→" TYPE BLOCK_EXPRESSION ";"
                                          | "subroutine" IDENTIFIER PRIME "(" PARAMETERS ")" "→" TYPE BLOCK_EXPRESSION ";"
                                          | "subroutine" IDENTIFIER "→" TYPE BLOCK_EXPRESSION ";"
                                          | "subroutine" IDENTIFIER PRIME "→" TYPE BLOCK_EXPRESSION ";"
                                          | "subroutine" IDENTIFIER "(" PARAMETERS ")" BLOCK_EXPRESSION ";"
                                          | "subroutine" IDENTIFIER BLOCK_EXPRESSION ";"
                                          ;

TYPE_DECLARATION                          : "type" IDENTIFIER "←" TYPE ";"
                                          ;

UNION_DECLARATION                         : "union" IDENTIFIER ";"
                                          | "union" IDENTIFIER "{" FIELDS "}" ";"
                                          ;

%%

void yy::parser::error(const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
