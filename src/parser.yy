%skeleton "lalr1.cc" /* -*- C++ -*- */

%require "3.2"

%defines

%define api.token.constructor

%define api.value.type variant

%define parse.assert

%code requires {
  #include <string>

  #include "include/ast.hh"

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
    #include "include/compiler.hh"
    #include "include/ast.hh"
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
  WILDCARD                          "_"
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
  ENUMERATION_KEYWORD               "enumeration"
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
  WHILE_KEYWORD                     "WhileLoopExpression"
;

%token <std::string> IDENTIFIER

%token <std::string> INTEGER 
%token <std::string> FLOATING_POINT 

%printer {
    // FIXME:
    //yyo << $$;
    yyo << typeid($$).name();
} <*>;

%left "←"
%left "<" "=" ">" "≠" "≤" "≥"
%left "+" "−"
%left "×" "÷"
%precedence UNARY_MINUS_SIGN
%left "as" "is"
%left "(" ")"
%left ":" ";" "," "."
%left "⟨" "⟩"

%%

%start ROOT;

ROOT                                    : 
                                        | STATEMENTS
                                        ;

STATEMENTS                              : STATEMENT
                                        | STATEMENT STATEMENTS
                                        ;

STATEMENT                               : DECLARATION ";"
                                        | EXPRESSION ";"
                                        | LOOP_STATEMENT ";"
                                        | BRANCH_STATEMENT ";"
                                        | LABELED_STATEMENT ";"
                                        | CONTROL_TRANSFER_STATEMENT ";"
                                        ;

EXPRESSION                              : PREFIX_EXPRESSION 
                                        | PREFIX_EXPRESSION BINARY_EXPRESSIONS
                                        ;
PREFIX_EXPRESSION                       : POSTFIX_EXPRESSION
                                        | PREFIX_OPERATOR POSTFIX_EXPRESSION
                                        ;
POSTFIX_EXPRESSION                      : PRIMARY_EXPRESSION
                                        | POSTFIX_EXPRESSION POSTFIX_OPERATOR
                                        | CALL_EXPRESSION
                                        | SUBSCRIPT_EXPRESSION
                                        ;
PRIMARY_EXPRESSION                      : IDENTIFIER 
                                        | IDENTIFIER GENERIC_ARGUMENT_CLAUSE
                                        | LITERAL_EXPRESSION
                                        | CLOSURE_EXPRESSION
                                        | PARENTHESIZED_EXPRESSION
                                        | WILDCARD_EXPRESSION
                                        | MEMBER_EXPRESSION
                                        ;






GENERIC_ARGUMENT_CLAUSE                 : "⟨" GENERIC_ARGUMENTS "⟩"
                                        ;
GENERIC_ARGUMENTS                       : GENERIC_ARGUMENT 
                                        | GENERIC_ARGUMENT "," GENERIC_ARGUMENTS
                                        ;
GENERIC_ARGUMENT                        : TYPE
                                        ;   
TYPE                                    : ARRAY_TYPE
                                        | FUNCTION_TYPE
                                        | TYPE_IDENTIFIER
                                        | TUPLE_TYPE
                                        | PRIMITIVE_TYPE
                                        | "(" TYPE ")"
                                        ;
ARRAY_TYPE                              : "[" ARRAY_TYPE_DIMENSIONS TYPE "]"
                                        ;
ARRAY_TYPE_DIMENSIONS                   : ARRAY_TYPE_DIMENSION
                                        | ARRAY_TYPE_DIMENSION "×" ARRAY_TYPE_DIMENSIONS
                                        ;
ARRAY_TYPE_DIMENSION                    : INTEGER
                                        ;
FUNCTION_TYPE                           : FUNCTION_TYPE_ARGUMENT_CLAUSE "→" TYPE
                                        ;
FUNCTION_TYPE_ARGUMENT_CLAUSE           : "(" ")"
                                        | "(" FUNCTION_TYPE_ARGUMENT_LIST ")"
                                        | "(" FUNCTION_TYPE_ARGUMENT_LIST "…" ")"
                                        ;
FUNCTION_TYPE_ARGUMENT_LIST             : FUNCTION_TYPE_ARGUMENT 
                                        | FUNCTION_TYPE_ARGUMENT "," FUNCTION_TYPE_ARGUMENT_LIST
                                        ;
FUNCTION_TYPE_ARGUMENT                  : TYPE 
                                        | ARGUMENT_LABEL TYPE_ANNOTATION
                                        ;
ARGUMENT_LABEL                          : IDENTIFIER
                                        ;
TYPE_ANNOTATION                         : ":" TYPE
                                        ;
TYPE_IDENTIFIER                         : TYPE_NAME
                                        | TYPE_NAME GENERIC_ARGUMENT_CLAUSE  
                                        | TYPE_NAME "." TYPE_IDENTIFIER
                                        | TYPE_NAME GENERIC_ARGUMENT_CLAUSE "." TYPE_IDENTIFIER
                                        ;
TYPE_NAME                               : IDENTIFIER
                                        ;
TUPLE_TYPE                              : "⟨" "⟩"
                                        | "⟨" TUPLE_TYPE_ELEMENT "×" TUPLE_TYPE_ELEMENTS "⟩"
                                        ;
TUPLE_TYPE_ELEMENTS                     : TUPLE_TYPE_ELEMENT 
                                        | TUPLE_TYPE_ELEMENT "×" TUPLE_TYPE_ELEMENTS
                                        ;
TUPLE_TYPE_ELEMENT                      : TUPLE_TYPE_ELEMENT_NAME TYPE_ANNOTATION 
                                        | TYPE
                                        ;
TUPLE_TYPE_ELEMENT_NAME                 : IDENTIFIER
                                        ;
PRIMITIVE_TYPE                          : BOOLEAN_TYPE
                                        | FLOATING_POINT_TYPE
                                        | INTEGER_TYPE
                                        ;
BOOLEAN_TYPE                            : "Boolean"
                                        ;
FLOATING_POINT_TYPE                     : FLOATING_POINT_SIZE "Floating-point"
                                        ;
FLOATING_POINT_SIZE                     : "32-bit"
                                        | "64-bit"
                                        ;
INTEGER_TYPE                            : INTEGER_TYPE_SIZE "Integer"
                                        | SIGNEDNESS INTEGER_TYPE_SIZE "Integer"
                                        ;
INTEGER_TYPE_SIZE                       :   "8-bit"
                                        |  "16-bit"
                                        |  "32-bit"
                                        |  "64-bit"
                                        | "128-bit"
                                        ;
SIGNEDNESS                              : "unsigned"
                                        ;
LITERAL_EXPRESSION                      : LITERAL
                                        | ARRAY_LITERAL
                                        | TUPLE_LITERAL
                                        ;
LITERAL                                 : BOOLEAN_LITERAL 
                                        | NUMERIC_LITERAL
                                        ;
BOOLEAN_LITERAL                         : "true"
                                        | "false"
                                        ;
NUMERIC_LITERAL                         : FLOATING_POINT_LITERAL
                                        | INTEGER_LITERAL
                                        ;
FLOATING_POINT_LITERAL                  : FLOATING_POINT
                                        | "−" FLOATING_POINT  %prec UNARY_MINUS_SIGN
                                        ;
INTEGER_LITERAL                         : INTEGER
                                        | "−" INTEGER         %prec UNARY_MINUS_SIGN
                                        ;
ARRAY_LITERAL                           : "[" ARRAY_LITERAL_ITEMS "]"
                                        ;
ARRAY_LITERAL_ITEMS                     : %empty
                                        | ARRAY_LITERAL_ITEM
                                        | ARRAY_LITERAL_ITEM "," ARRAY_LITERAL_ITEMS
                                        ;
ARRAY_LITERAL_ITEM                      : EXPRESSION
                                        ;
TUPLE_LITERAL                           : "⟨" TUPLE_LITERAL_ITEMS "⟩"
                                        ;
TUPLE_LITERAL_ITEMS                     : %empty
                                        | TUPLE_LITERAL_ITEM
                                        | TUPLE_LITERAL_ITEM "," TUPLE_LITERAL_ITEMS
                                        ;
TUPLE_LITERAL_ITEM                      : EXPRESSION
                                        | IDENTIFIER ":" EXPRESSION
                                        ;
CLOSURE_EXPRESSION                      : CLOSURE_HEAD CLOSURE_SIGNATURE BLOCK_EXPRESSION
                                        | CLOSURE_HEAD BLOCK_EXPRESSION
                                        ;
CLOSURE_HEAD                            : "λ"
                                        ;
CLOSURE_SIGNATURE                       : CLOSURE_PARAMETER_CLAUSE
                                        | CLOSURE_PARAMETER_CLAUSE CLOSURE_RETURN_TYPE
                                        ;
CLOSURE_PARAMETER_CLAUSE                : "(" CLOSURE_PARAMETERS ")" 
                                        ;
CLOSURE_PARAMETERS                      : %empty
                                        | CLOSURE_PARAMETER
                                        | CLOSURE_PARAMETER "," CLOSURE_PARAMETERS
                                        ;
CLOSURE_PARAMETER                       : CLOSURE_PARAMETER_NAME
                                        | CLOSURE_PARAMETER_NAME TYPE_ANNOTATION
                                        | CLOSURE_PARAMETER_NAME TYPE_ANNOTATION "…"
                                        ;
CLOSURE_PARAMETER_NAME                  : IDENTIFIER
                                        ;
CLOSURE_RETURN_TYPE                     : "→" TYPE
BLOCK_EXPRESSION                        : "{" "}"
                                        | "{" STATEMENTS "}"
                                        ;
                                        ;
PARENTHESIZED_EXPRESSION                : "(" EXPRESSION ")"
                                        ;
WILDCARD_EXPRESSION                     : "_"
                                        ;
MEMBER_EXPRESSION                       : POSTFIX_EXPRESSION "." IDENTIFIER
                                        | POSTFIX_EXPRESSION "." IDENTIFIER GENERIC_ARGUMENT_CLAUSE
                                        | POSTFIX_EXPRESSION "." IDENTIFIER "(" ARGUMENT_NAMES ")"
                                        ;
ARGUMENT_NAMES                          : ARGUMENT_NAME
                                        | ARGUMENT_NAME ARGUMENT_NAMES
                                        ;                                
ARGUMENT_NAME                           : IDENTIFIER ":"
                                        ;
POSTFIX_OPERATOR                        : "!"
                                        | "?"
                                        ;
CALL_EXPRESSION                         : POSTFIX_EXPRESSION CALL_ARGUMENT_CLAUSE
                                        ;
CALL_ARGUMENT_CLAUSE                    : "(" ")"
                                        | "(" CALL_ARGUMENTS ")"
                                        ;
CALL_ARGUMENTS                          : CALL_ARGUMENT
                                        | CALL_ARGUMENT "," CALL_ARGUMENTS
                                        ;
CALL_ARGUMENT                           : EXPRESSION
                                        | IDENTIFIER ":" EXPRESSION
                                        ;
SUBSCRIPT_EXPRESSION                    : POSTFIX_EXPRESSION "[" CALL_ARGUMENTS "]"
                                        ;
BINARY_EXPRESSIONS                      : BINARY_EXPRESSION
                                        | BINARY_EXPRESSION BINARY_EXPRESSIONS
                                        ;
BINARY_EXPRESSION                       : BINARY_OPERATOR PREFIX_EXPRESSION
                                        | ASSIGNMENT_OPERATOR PREFIX_EXPRESSION 
                                        | TYPE_CASTING_OPERATOR
                                        ;
ASSIGNMENT_OPERATOR                     : "←"
                                        ;
TYPE_CASTING_OPERATOR                   : "is" TYPE 
                                        | "as" TYPE 
                                        ;
BINARY_OPERATOR                         : "+"
                                        | "<"
                                        | "="
                                        | ">"
                                        | "÷"
                                        | "∧"
                                        | "∨"
                                        | "≠"
                                        | "≤"
                                        | "≥"
                                        | "⊻"
                                        ;
PREFIX_OPERATOR                         : "¬"
                                        ;
DECLARATION                             : CONSTANT_DECLARATION
                                        | TYPE_ALIAS_DECLARATION
                                        | SUBROUTINE_DECLARATION
                                        | UNION_DECLARATION
                                        | ENUMERATION_DECLARATION
                                        | RECORD_DECLARATION
                                        ;

PATTERN                                 : WILDCARD_PATTERN
                                        | WILDCARD_PATTERN TYPE_ANNOTATION
                                        | IDENTIFIER_PATTERN
                                        | IDENTIFIER_PATTERN TYPE_ANNOTATION
                                        | TUPLE_PATTERN
                                        | TUPLE_PATTERN TYPE_ANNOTATION
                                        | TYPE_CASTING_PATTERN
                                        | EXPRESSION_PATTERN
                                        ;
WILDCARD_PATTERN                        : "_"
                                        ;
IDENTIFIER_PATTERN                      : IDENTIFIER
                                        ;
TUPLE_PATTERN                           : "⟨" "⟩"
                                        | "⟨" TUPLE_PATTERN_ELEMENTS "⟩"
                                        ;
TUPLE_PATTERN_ELEMENTS                  : TUPLE_PATTERN_ELEMENT
                                        | TUPLE_PATTERN_ELEMENT "," TUPLE_PATTERN_ELEMENTS
                                        ;
TUPLE_PATTERN_ELEMENT                   : PATTERN 
                                        | IDENTIFIER ":" PATTERN
                                        ;
TYPE_CASTING_PATTERN                    : IS_PATTERN 
                                        | AS_PATTERN
                                        ;
IS_PATTERN                              : "is" TYPE
                                        ;
AS_PATTERN                              : PATTERN "as" TYPE
                                        ;
EXPRESSION_PATTERN                      : EXPRESSION
                                        ;

GENERIC_PARAMETER_CLAUSE                : "⟨" GENERIC_PARAMETERS "⟩"
                                        ;
GENERIC_PARAMETERS                      : GENERIC_PARAMETER 
                                        | GENERIC_PARAMETER "," GENERIC_PARAMETERS
                                        ;
GENERIC_PARAMETER                       : TYPE_NAME
                                        | TYPE_NAME ":" TYPE_IDENTIFIER
                                        ;


/*
 *  2.0   DECLARATIONS
 */

/*
 *  2.1   SUBROUTINE
 */

SUBROUTINE_DECLARATION                  : SUBROUTINE_DECLARATION_HEAD SUBROUTINE_NAME SUBROUTINE_SIGNATURE
                                        | SUBROUTINE_DECLARATION_HEAD SUBROUTINE_NAME SUBROUTINE_SIGNATURE SUBROUTINE_BODY
                                        | SUBROUTINE_DECLARATION_HEAD SUBROUTINE_NAME GENERIC_PARAMETER_CLAUSE SUBROUTINE_SIGNATURE
                                        | SUBROUTINE_DECLARATION_HEAD SUBROUTINE_NAME GENERIC_PARAMETER_CLAUSE SUBROUTINE_SIGNATURE SUBROUTINE_BODY
                                        ;
SUBROUTINE_DECLARATION_HEAD             : "subroutine"
                                        ;
SUBROUTINE_NAME                         : IDENTIFIER 
                                        ;
SUBROUTINE_SIGNATURE                    : PARAMETER_CLAUSE
                                        | PARAMETER_CLAUSE SUBROUTINE_RETURN_TYPE
                                        ;
SUBROUTINE_RETURN_TYPE                  : "→" TYPE
                                        ;
SUBROUTINE_BODY                         : BLOCK_EXPRESSION
                                        ;
PARAMETER_CLAUSE                        : "(" SUBROUTINE_PARAMETERS ")"
                                        ;
SUBROUTINE_PARAMETERS                   : %empty
                                        | SUBROUTINE_PARAMETER
                                        | SUBROUTINE_PARAMETER "," SUBROUTINE_PARAMETERS
                                        ;
SUBROUTINE_PARAMETER                    : SUBROUTINE_PARAMETER_NAME TYPE_ANNOTATION
                                        | SUBROUTINE_PARAMETER_NAME TYPE_ANNOTATION DEFAULT_ARGUMENT_CLAUSE
                                        | SUBROUTINE_PARAMETER_NAME TYPE_ANNOTATION "…"
                                        ;
SUBROUTINE_PARAMETER_NAME               : IDENTIFIER
                                        ;
DEFAULT_ARGUMENT_CLAUSE                 : "←" EXPRESSION
                                        ;

/*
 *  2.2   TYPE ALIAS
 */

TYPE_ALIAS_DECLARATION                  : TYPE_ALIAS_DECLARATION_HEAD TYPE_ALIAS_NAME TYPE_ALIAS_ASSIGNMENT
                                        | TYPE_ALIAS_DECLARATION_HEAD TYPE_ALIAS_NAME GENERIC_PARAMETER_CLAUSE TYPE_ALIAS_ASSIGNMENT
                                        ;
TYPE_ALIAS_DECLARATION_HEAD             : "type"
                                        ;
TYPE_ALIAS_NAME                         : IDENTIFIER
                                        ;
TYPE_ALIAS_ASSIGNMENT                   : "←" TYPE
                                        ;

/*
 *  2.3   RECORD 
 */

RECORD_DECLARATION                      : RECORD_DECLARATION_HEAD RECORD_DECLARATION_NAME RECORD_BODY
                                        | RECORD_DECLARATION_HEAD RECORD_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE RECORD_BODY
                                        ;
RECORD_DECLARATION_HEAD                 : "record"
                                        ;
RECORD_DECLARATION_NAME                 : IDENTIFIER
                                        ;
RECORD_BODY                             : "{" RECORD_FIELDS "}"
                                        ;
RECORD_FIELDS                           : %empty
                                        | RECORD_FIELD
                                        | RECORD_FIELD "," RECORD_FIELDS
                                        ;
RECORD_FIELD                            : RECORD_FIELD_NAME TYPE_ANNOTATION
                                        ;
RECORD_FIELD_NAME                       : IDENTIFIER
                                        ;

/*
 *  2.4   ENUMERATION 
 */

ENUMERATION_DECLARATION                 : ENUMERATION_DECLARATION_HEAD ENUMERATION_DECLARATION_NAME ENUMERATION_DECLARATION_BODY
                                        | ENUMERATION_DECLARATION_HEAD ENUMERATION_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE ENUMERATION_DECLARATION_BODY
                                        ;
ENUMERATION_DECLARATION_HEAD            : "enumeration"
                                        ;
ENUMERATION_DECLARATION_NAME            : IDENTIFIER
                                        ;
ENUMERATION_DECLARATION_BODY            : "{" ENUMERATION_DECLARATION_FIELDS "}"
                                        ; 
ENUMERATION_DECLARATION_FIELDS          : ENUMERATION_DECLARATION_FIELD
                                        | ENUMERATION_DECLARATION_FIELD "," ENUMERATION_DECLARATION_FIELDS
                                        ;
ENUMERATION_DECLARATION_FIELD           : ENUMERATION_DECLARATION_FIELD_NAME
                                        | ENUMERATION_DECLARATION_FIELD_NAME ENUMERATION_DECLARATION_TUPLE
                                        | ENUMERATION_DECLARATION_FIELD_NAME ENUMERATION_DECLARATION_RECORD
                                        | ENUMERATION_DECLARATION_FIELD_NAME ENUMERATION_DECLARATION_ASSIGNMENT
                                        ;
ENUMERATION_DECLARATION_FIELD_NAME      : IDENTIFIER
                                        ;
ENUMERATION_DECLARATION_TUPLE           : "⟨" TUPLE_TYPE_ELEMENTS "⟩"
                                        ;
ENUMERATION_DECLARATION_RECORD          : "{" RECORD_FIELDS "}"
                                        ;                                      
ENUMERATION_DECLARATION_ASSIGNMENT      : "←" EXPRESSION
                                        ;

/*
 *  2.5   UNION
 */

UNION_DECLARATION                       : UNION_DECLARATION_HEAD UNION_DECLARATION_NAME UNION_DECLARATION_BODY
                                        | UNION_DECLARATION_HEAD UNION_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE UNION_DECLARATION_BODY
                                        ;
UNION_DECLARATION_HEAD                  : "union"
                                        ;
UNION_DECLARATION_NAME                  : IDENTIFIER
                                        ;
UNION_DECLARATION_BODY                  : "{" RECORD_FIELDS "}"
                                        ;

/*
 *  2.6   CONSTANT
 */

CONSTANT_DECLARATION                    : CONSTANT_DECLARATION_HEAD CONSTANT_DECLARATION_NAME TYPE_ANNOTATION CONSTANT_DECLARATION_ASSIGNMENT
                                        ;
CONSTANT_DECLARATION_HEAD               : "constant"
                                        ;
CONSTANT_DECLARATION_NAME               : IDENTIFIER
                                        ;
CONSTANT_DECLARATION_ASSIGNMENT         : "←" EXPRESSION
                                        ;

/*
 *  4.0   EXPRESSIONS
 */





LOOP_STATEMENT                          : FOR_IN_STATEMENT
                                        | WHILE_STATEMENT
                                        ;
FOR_IN_STATEMENT                        : "for" PATTERN "in" EXPRESSION BLOCK_EXPRESSION
                                        ;
WHILE_STATEMENT                         : "WhileLoopExpression" EXPRESSION BLOCK_EXPRESSION
                                        ;
BRANCH_STATEMENT                        : IF_STATEMENT
                                        | SWITCH_STATEMENT
                                        ;
IF_STATEMENT                            : "if" CONDITION_LIST BLOCK_EXPRESSION
                                        | "if" CONDITION_LIST BLOCK_EXPRESSION ELSE_CLAUSE
                                        ;
CONDITION_LIST                          : CONDITION 
                                        | CONDITION "," CONDITION_LIST
                                        ;
CONDITION                               : EXPRESSION 
                                        | CASE_CONDITION
                                        ;
CASE_CONDITION                          : "case" PATTERN
                                        ;
ELSE_CLAUSE                             : "else" BLOCK_EXPRESSION 
                                        | "else" IF_STATEMENT
                                        ;
SWITCH_STATEMENT                        : "switch" EXPRESSION "{" "}"
                                        | "switch" EXPRESSION "{" SWITCH_CASES "}"
                                        ;
SWITCH_CASES                            : SWITCH_CASE 
                                        | SWITCH_CASE SWITCH_CASES
                                        ;
SWITCH_CASE                             : CASE_LABEL STATEMENTS
                                        | DEFAULT_LABEL STATEMENTS
                                        ;
CASE_LABEL                              : "case" CASE_ITEMS ":"
                                        ;
CASE_ITEMS                              : PATTERN
                                        | PATTERN WHERE_CLAUSE 
                                        | PATTERN "," CASE_ITEMS
                                        | PATTERN WHERE_CLAUSE "," CASE_ITEMS
                                        ;
WHERE_CLAUSE                            : "where" WHERE_EXPRESSION
                                        ;
WHERE_EXPRESSION                        : EXPRESSION
                                        ;
DEFAULT_LABEL                           : "default" ":"
                                        ;
LABELED_STATEMENT                       : STATEMENT_LABEL LOOP_STATEMENT 
                                        | STATEMENT_LABEL IF_STATEMENT 
                                        | STATEMENT_LABEL SWITCH_STATEMENT 
                                        ;
STATEMENT_LABEL                         : LABEL_NAME ":"
                                        ;
LABEL_NAME                              : IDENTIFIER
                                        ;
CONTROL_TRANSFER_STATEMENT              : BREAK_STATEMENT
                                        | CONTINUE_STATEMENT
                                        | RETURN_STATEMENT
                                        ;
BREAK_STATEMENT                         : "break"
                                        | "break" LABEL_NAME
                                        ;
CONTINUE_STATEMENT                      : "continue"
                                        | "continue" LABEL_NAME
                                        ;
RETURN_STATEMENT                        : "return"
                                        | "return" EXPRESSION
                                        ;

%%

void yy::parser::error(const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
