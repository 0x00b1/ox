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

%token <int> INTEGER 
%token <int> FLOATING_POINT 

%token <int> NUMBER 

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
%type <int> LITERAL_EXPRESSION

%printer {
    yyo << $$;
} <*>;

%%

%start MODULE_DECLARATION;

%left "+" "−";
%left "×" "÷";

/*
 *    TYPES
 */
TYPE                                      : PRIMITIVE_TYPE
                                          | COMPOSITE_TYPE
                                          | REFERENCE_TYPE
                                          | PATH_TYPE
                                          ;
PRIMITIVE_TYPE                            : BOOLEAN_PRIMITIVE_TYPE
                                          | FLOATING_POINT_PRIMITIVE_TYPE
                                          | INTEGER_PRIMITIVE_TYPE
                                          ;
BOOLEAN_PRIMITIVE_TYPE                    : "Boolean"
                                          ;
FLOATING_POINT_PRIMITIVE_TYPE             : FLOATING_POINT_PRIMITIVE_TYPE_SIZE "Floating-point"
                                          ;
FLOATING_POINT_PRIMITIVE_TYPE_SIZE        : "16-bit"
                                          | "32-bit"
                                          ;
INTEGER_PRIMITIVE_TYPE                    : INTEGER_PRIMITIVE_TYPE_SIZE "Integer"
                                          ;
INTEGER_PRIMITIVE_TYPE_SIZE               :  "8-bit"
                                          | "16-bit"
                                          | "32-bit"
                                          | "64-bit"
                                          ;
COMPOSITE_TYPE                            : ARRAY_COMPOSITE_TYPE
                                          | TUPLE_COMPOSITE_TYPE
                                          ;
ARRAY_COMPOSITE_TYPE                      : "[" ARRAY_COMPOSITE_TYPE_ITEM "×" TYPE "]"
                                          ;
ARRAY_COMPOSITE_TYPE_ITEM                 : EXPRESSION
                                          | ARRAY_COMPOSITE_TYPE_ITEM "×" EXPRESSION
                                          ;
TUPLE_COMPOSITE_TYPE                      : "⟨" TUPLE_COMPOSITE_TYPE_ITEM "⟩"
                                          ;
TUPLE_COMPOSITE_TYPE_ITEM                 : TYPE
                                          | TUPLE_COMPOSITE_TYPE_ITEM "×" TYPE
                                          ;
REFERENCE_TYPE                            : "reference" TYPE
                                          ;
PATH_TYPE                                 : IDENTIFIER
                                          | PATH_TYPE "::" IDENTIFIER
                                          ;
/*
 *    DECLARATIONS
 */
DECLARATIONS                              : %empty
                                          | DECLARATION
                                          | DECLARATIONS DECLARATION
                                          ;
DECLARATION                               : MODULE_DECLARATION
                                          | SUBROUTINE_DECLARATION
                                          | TYPE_DECLARATION
                                          | RECORD_DECLARATION
                                          | ENUMERATED_DECLARATION
                                          | UNION_DECLARATION
                                          | CONSTANT_DECLARATION
                                          ;
MODULE_DECLARATION                        : "module" IDENTIFIER "{" DECLARATIONS "}" ";" {
                                            std::cout << "module" << std::endl;
                                          }
                                          ;
SUBROUTINE_DECLARATION                    : "subroutine" IDENTIFIER "(" SUBROUTINE_DECLARATION_PARAMETERS ")" "→" TYPE BLOCK_EXPRESSION ";" {
                                            std::cout << "(SUBROUTINE " << std::endl;
                                          }
                                          ;
SUBROUTINE_DECLARATION_PARAMETERS         : SUBROUTINE_DECLARATION_PARAMETER
                                          | SUBROUTINE_DECLARATION_PARAMETERS "," SUBROUTINE_DECLARATION_PARAMETER
                                          ;
SUBROUTINE_DECLARATION_PARAMETER          : IDENTIFIER ":" TYPE
                                          ;
TYPE_DECLARATION                          : "type" IDENTIFIER "←" TYPE ";"
                                          ;
RECORD_DECLARATION                        : "record" IDENTIFIER "{" RECORD_DECLARATION_FIELDS "}" ";"
                                          ;
RECORD_DECLARATION_FIELDS                 : %empty
                                          | RECORD_DECLARATION_FIELD
                                          | RECORD_DECLARATION_FIELDS "," RECORD_DECLARATION_FIELD
                                          ;
RECORD_DECLARATION_FIELD                  : IDENTIFIER ":" TYPE
                                          ;
ENUMERATED_DECLARATION                    : "enumerated" IDENTIFIER "{" ENUMERATED_DECLARATION_ITEMS "}" ";" {
                                            std::cout << "enumerated" << std::endl;
                                          }
                                          ;
ENUMERATED_DECLARATION_ITEMS              : ENUMERATED_DECLARATION_ITEM
                                          | ENUMERATED_DECLARATION_ITEMS "," ENUMERATED_DECLARATION_ITEM
                                          ;
ENUMERATED_DECLARATION_ITEM               : IDENTIFIER
                                          ;
UNION_DECLARATION                         : "union" IDENTIFIER "{" UNION_DECLARATION_ITEMS "}" ";"
                                          ;
UNION_DECLARATION_ITEMS                   : %empty
                                          | UNION_DECLARATION_ITEM
                                          | UNION_DECLARATION_ITEMS "," UNION_DECLARATION_ITEM
                                          ;
UNION_DECLARATION_ITEM                    : IDENTIFIER ":" TYPE
                                          ;
CONSTANT_DECLARATION                      : "constant" IDENTIFIER ":" TYPE "←" EXPRESSION ";"
                                          ;
/*
 *    EXPRESSIONS
 */
EXPRESSIONS                               : EXPRESSION
                                          | EXPRESSIONS EXPRESSION {
                                            compiler.result = $2;
                                          }
                                          ;
EXPRESSION                                : LITERAL_EXPRESSION
                                          | IDENTIFIER {
                                            $$ = compiler.variables[$1];
                                          }
                                          | OPERATOR_EXPRESSION
                                          | CONDITIONAL_EXPRESSION
                                          | GROUPED_EXPRESSION
                                          ;
LITERAL_EXPRESSION                        : INTEGER
                                          | FLOATING_POINT
                                          ;
BLOCK_EXPRESSION                          : "{" EXPRESSIONS "}"
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
