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
  WHILE_KEYWORD                     "while"
;

%token <std::string> IDENTIFIER

%token <std::string> INTEGER 
%token <std::string> FLOATING_POINT 

%printer {
    yyo << $$;
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

%type <std::string> ENUMERATION_DECLARATION_NAME;
%type <std::string> RECORD_DECLARATION_NAME;
%type <std::string> SUBROUTINE_NAME;
%type <std::string> TYPE_ALIAS_NAME;
%type <std::string> UNION_DECLARATION_NAME;

%type <AST::ArrayExpression*> ARRAY_LITERAL;
%type <std::vector<AST::Node*>*> ARRAY_LITERAL_ITEMS;
%type <AST::Node*> ARRAY_LITERAL_ITEM;

%type <AST::TupleExpression*> TUPLE_LITERAL;
%type <std::vector<AST::Node*>*> TUPLE_LITERAL_ITEMS;
%type <AST::Node*> TUPLE_LITERAL_ITEM;

%type <AST::BooleanLiteral*> BOOLEAN_LITERAL;
%type <AST::FloatingPointLiteral*> FLOATING_POINT_LITERAL;
%type <AST::IntegerLiteral*> INTEGER_LITERAL;
%type <AST::EnumerationDeclaration*> ENUMERATION_DECLARATION;
%type <AST::RecordDeclaration*> RECORD_DECLARATION;
%type <AST::SubroutineDeclaration*> SUBROUTINE_DECLARATION;
%type <AST::TypeDeclaration*> TYPE_ALIAS_DECLARATION;
%type <AST::UnionDeclaration*> UNION_DECLARATION;

%%

%start TOP_LEVEL_DECLARATION;

/*
 *  LEXICAL SYNTAX
 */

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
POSTFIX_OPERATOR                        : "!"
                                        | "?"
                                        ;



/*
 *  TYPES
 */

TYPE                                    : ARRAY_TYPE
                                        | FUNCTION_TYPE
                                        | TYPE_IDENTIFIER
                                        | TUPLE_TYPE
                                        | PRIMITIVE_TYPE
                                        | "(" TYPE ")"
                                        ;

/*
 *  ARRAY TYPE
 */

ARRAY_TYPE                              : "[" ARRAY_TYPE_DIMENSIONS TYPE "]"
                                        ;
ARRAY_TYPE_DIMENSIONS                   : ARRAY_TYPE_DIMENSION
                                        | ARRAY_TYPE_DIMENSION "×" ARRAY_TYPE_DIMENSIONS
                                        ;
ARRAY_TYPE_DIMENSION                    : INTEGER
                                        ;

/*
 *  FUNCTION TYPE
 */ 

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

/*
 *  TYPE IDENTIFIER
 */

TYPE_IDENTIFIER                         : TYPE_NAME
                                        | TYPE_NAME GENERIC_ARGUMENT_CLAUSE  
                                        | TYPE_NAME "." TYPE_IDENTIFIER
                                        | TYPE_NAME GENERIC_ARGUMENT_CLAUSE "." TYPE_IDENTIFIER
                                        ;
TYPE_NAME                               : IDENTIFIER
                                        ;

/*
 *  TUPLE TYPE
 */

TUPLE_TYPE                              : "⟨" "⟩"
                                        | "⟨" TUPLE_TYPE_ELEMENT "×" TUPLE_TYPE_ELEMENT_LIST "⟩"
                                        ;
TUPLE_TYPE_ELEMENT_LIST                 : TUPLE_TYPE_ELEMENT 
                                        | TUPLE_TYPE_ELEMENT "×" TUPLE_TYPE_ELEMENT_LIST
                                        ;
TUPLE_TYPE_ELEMENT                      : ELEMENT_NAME TYPE_ANNOTATION 
                                        | TYPE
                                        ;
ELEMENT_NAME                            : IDENTIFIER
                                        ;

/*
 *  TYPE ANNOTATION
 */

TYPE_ANNOTATION                         : ":" TYPE
                                        ;

/*
 *  PRIMITIVE TYPE
 */

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

/*
 *  GENERIC PARAMETERS AND ARGUMENTS
 */

GENERIC_PARAMETER_CLAUSE                : "⟨" GENERIC_PARAMETER_LIST "⟩"
                                        ;
GENERIC_PARAMETER_LIST                  : GENERIC_PARAMETER 
                                        | GENERIC_PARAMETER "," GENERIC_PARAMETER_LIST
                                        ;
GENERIC_PARAMETER                       : TYPE_NAME
                                        | TYPE_NAME ":" TYPE_IDENTIFIER
                                        ;

GENERIC_ARGUMENT_CLAUSE                 : "⟨" GENERIC_ARGUMENT_LIST "⟩"
                                        ;
GENERIC_ARGUMENT_LIST                   : GENERIC_ARGUMENT 
                                        | GENERIC_ARGUMENT "," GENERIC_ARGUMENT_LIST
                                        ;
GENERIC_ARGUMENT                        : TYPE
                                        ;   

/*
 *  EXPRESSIONS
 */

EXPRESSION                              : PREFIX_EXPRESSION 
                                        | PREFIX_EXPRESSION BINARY_EXPRESSIONS
                                        ;
PREFIX_EXPRESSION                       : POSTFIX_EXPRESSION
                                        | PREFIX_OPERATOR POSTFIX_EXPRESSION
                                        ;

BINARY_EXPRESSION                       : BINARY_OPERATOR PREFIX_EXPRESSION
                                        | ASSIGNMENT_OPERATOR PREFIX_EXPRESSION
                                        | TYPE_CASTING_OPERATOR
                                        ;
                                
BINARY_EXPRESSIONS                      : BINARY_EXPRESSION 
                                        | BINARY_EXPRESSION BINARY_EXPRESSIONS
                                        ;

ASSIGNMENT_OPERATOR                     : "←"
                                        ;

TYPE_CASTING_OPERATOR                   : "is" TYPE
                                        | "as" TYPE
                                        ;

PRIMARY_EXPRESSION                      : IDENTIFIER 
                                        | IDENTIFIER GENERIC_ARGUMENT_CLAUSE
                                        | LITERAL_EXPRESSION
                                        | CLOSURE_EXPRESSION
                                        | PARENTHESIZED_EXPRESSION
                                        | WILDCARD_EXPRESSION
                                        | EXPLICIT_MEMBER_EXPRESSION
                                        ;

LITERAL_EXPRESSION                      : LITERAL
                                        | ARRAY_LITERAL
                                        | TUPLE_LITERAL
                                        ;

LITERAL                                 : BOOLEAN_LITERAL 
                                        | NUMERIC_LITERAL
                                        ;

BOOLEAN_LITERAL                         : "true" {
                                          $$ = new AST::BooleanLiteral(true);
                                        }
                                        | "false" {
                                          $$ = new AST::BooleanLiteral(false);
                                        }
                                        ;
NUMERIC_LITERAL                         : FLOATING_POINT_LITERAL
                                        | INTEGER_LITERAL
                                        ;
FLOATING_POINT_LITERAL                  : FLOATING_POINT {
                                          $$ = new AST::FloatingPointLiteral($1);
                                        }
                                        | "−" FLOATING_POINT  %prec UNARY_MINUS_SIGN {
                                          $$ = new AST::FloatingPointLiteral($2);
                                        }
                                        ;
INTEGER_LITERAL                         : INTEGER {
                                          $$ = new AST::IntegerLiteral($1);
                                        }
                                        | "−" INTEGER         %prec UNARY_MINUS_SIGN {
                                          $$ = new AST::IntegerLiteral($2);
                                        }
                                        ;

ARRAY_LITERAL                           : "[" ARRAY_LITERAL_ITEMS "]" {
                                          $$ = new AST::ArrayExpression($2);
                                        }
                                        ;
ARRAY_LITERAL_ITEMS                     : %empty {
                                          $$ = new std::vector<AST::Node*>();
                                        }
                                        | ARRAY_LITERAL_ITEM {
                                          $$ = new std::vector<AST::Node*>();

                                          $$ -> push_back($1);
                                        }
                                        | ARRAY_LITERAL_ITEM "," ARRAY_LITERAL_ITEMS {
                                          std::vector<AST::Node*> *items = $3;

                                          items -> push_back($1);

                                          $$ = items;
                                        }
                                        ;
ARRAY_LITERAL_ITEM                      : EXPRESSION
                                        ;

TUPLE_LITERAL                           : "⟨" TUPLE_LITERAL_ITEMS "⟩" {
                                          $$ = new AST::TupleExpression($2);
                                        }
                                        ;
TUPLE_LITERAL_ITEMS                     : %empty {
                                          $$ = new std::vector<AST::Node*>();
                                        }
                                        | TUPLE_LITERAL_ITEM {
                                          $$ = new std::vector<AST::Node*>();

                                          $$ -> push_back($1);
                                        }
                                        | TUPLE_LITERAL_ITEM "," TUPLE_LITERAL_ITEMS {
                                          std::vector<AST::Node*> *items = $3;

                                          items -> push_back($1);

                                          $$ = items;
                                        }
                                        ;
TUPLE_LITERAL_ITEM                      : EXPRESSION
                                        | IDENTIFIER ":" EXPRESSION
                                        ;

CLOSURE_EXPRESSION                      : CLOSURE_HEAD CLOSURE_SIGNATURE CLOSURE_BLOCK
                                        | CLOSURE_HEAD CLOSURE_BLOCK
                                        ;
CLOSURE_HEAD                            : "λ"
                                        ;
CLOSURE_SIGNATURE                       : CLOSURE_PARAMETER_CLAUSE 
                                        | CLOSURE_PARAMETER_CLAUSE SUBROUTINE_RESULT
                                        ;
CLOSURE_PARAMETER_CLAUSE                : "(" ")" 
                                        | "(" CLOSURE_PARAMETER_LIST ")" 
                                        ;
CLOSURE_PARAMETER_LIST                  : CLOSURE_PARAMETER 
                                        | CLOSURE_PARAMETER "," CLOSURE_PARAMETER_LIST
                                        ;
CLOSURE_PARAMETER                       : CLOSURE_PARAMETER_NAME
                                        | CLOSURE_PARAMETER_NAME TYPE_ANNOTATION
                                        | CLOSURE_PARAMETER_NAME TYPE_ANNOTATION "…"
                                        ;
CLOSURE_PARAMETER_NAME                  : IDENTIFIER
                                        ;
CLOSURE_BLOCK                           : "{" "}"
                                        | "{" STATEMENTS "}"
                                        ;

PARENTHESIZED_EXPRESSION                : "(" EXPRESSION ")"
                                        ;

WILDCARD_EXPRESSION                     : "_"
                                        ;

POSTFIX_EXPRESSION                      : PRIMARY_EXPRESSION
                                        | POSTFIX_EXPRESSION POSTFIX_OPERATOR
                                        | CALL_EXPRESSION
                                        | SUBSCRIPT_EXPRESSION
                                        ;

CALL_EXPRESSION                         : POSTFIX_EXPRESSION CALL_ARGUMENT_CLAUSE
                                        ;
CALL_ARGUMENT_CLAUSE                    : "(" ")" 
                                        | "(" CALL_ARGUMENT_LIST ")"
                                        ;
CALL_ARGUMENT_LIST                      : CALL_ARGUMENT 
                                        | CALL_ARGUMENT "," CALL_ARGUMENT_LIST
                                        ;
CALL_ARGUMENT                           : EXPRESSION 
                                        | IDENTIFIER ":" EXPRESSION
                                        ;

SUBSCRIPT_EXPRESSION                    : POSTFIX_EXPRESSION "[" CALL_ARGUMENT_LIST "]"
                                        ;

EXPLICIT_MEMBER_EXPRESSION              : POSTFIX_EXPRESSION "." IDENTIFIER
                                        | POSTFIX_EXPRESSION "." IDENTIFIER GENERIC_ARGUMENT_CLAUSE
                                        | POSTFIX_EXPRESSION "." IDENTIFIER "(" ARGUMENT_NAMES ")"
                                        ;
ARGUMENT_NAMES                          : ARGUMENT_NAME
                                        | ARGUMENT_NAME ARGUMENT_NAMES
                                        ;                                
ARGUMENT_NAME                           : IDENTIFIER ":"
                                        ;

/*
 *  STATEMENTS
 */

STATEMENT                               : EXPRESSION ";"
                                        | DECLARATION ";"
                                        | LOOP_STATEMENT ";"
                                        | BRANCH_STATEMENT ";"
                                        | LABELED_STATEMENT ";"
                                        | CONTROL_TRANSFER_STATEMENT ";"
                                        ;

STATEMENTS                              : STATEMENT
                                        | STATEMENT STATEMENTS 
                                        ;

LOOP_STATEMENT                          : FOR_IN_STATEMENT
                                        | WHILE_STATEMENT
                                        ;

FOR_IN_STATEMENT                        : "for" PATTERN "in" EXPRESSION CODE_BLOCK
                                        ;

WHILE_STATEMENT                         : "while" CONDITION_LIST CODE_BLOCK
                                        ;
CONDITION_LIST                          : CONDITION 
                                        | CONDITION "," CONDITION_LIST

CONDITION                               : EXPRESSION 
                                        | CASE_CONDITION
                                        ;
CASE_CONDITION                          : "case" PATTERN INITIALIZER
                                        ;

BRANCH_STATEMENT                        : IF_STATEMENT
                                        | SWITCH_STATEMENT
                                        ;

IF_STATEMENT                            : "if" CONDITION_LIST CODE_BLOCK
                                        | "if" CONDITION_LIST CODE_BLOCK ELSE_CLAUSE
                                        ;
ELSE_CLAUSE                             : "else" CODE_BLOCK 
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
CASE_LABEL                              : "case" CASE_ITEM_LIST ":"
                                        ;
CASE_ITEM_LIST                          : PATTERN
                                        | PATTERN WHERE_CLAUSE 
                                        | PATTERN "," CASE_ITEM_LIST
                                        | PATTERN WHERE_CLAUSE "," CASE_ITEM_LIST
                                        ;
DEFAULT_LABEL                           : "default" ":"
                                        ;
WHERE_CLAUSE                            : "where" WHERE_EXPRESSION
                                        ;
WHERE_EXPRESSION                        : EXPRESSION
                                        ;

LABELED_STATEMENT                       : STATEMENT_LABEL LOOP_STATEMENT
                                        | STATEMENT_LABEL IF_STATEMENT
                                        | STATEMENT_LABEL SWITCH_STATEMENT
                                        ;
STATEMENT_LABEL                         : LABEL_NAME ":"
                                        ;
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

/*
 *  DECLARATIONS
 */

DECLARATION                             : CONSTANT_DECLARATION
                                        | TYPE_ALIAS_DECLARATION
                                        | SUBROUTINE_DECLARATION
                                        | UNION_DECLARATION
                                        | ENUMERATION_DECLARATION
                                        | RECORD_DECLARATION
                                        ;

TOP_LEVEL_DECLARATION                   : 
                                        | STATEMENTS
                                        ;

CODE_BLOCK                              : "{" "}"
                                        | "{" STATEMENTS "}"
                                        ;

/*
 *  CONSTANT DECLARATION
 */

CONSTANT_DECLARATION                    : CONSTANT_DECLARATION_HEAD PATTERN_INITIALIZER_LIST
                                        ;
CONSTANT_DECLARATION_HEAD               : "constant"
                                        ;
PATTERN_INITIALIZER_LIST                : PATTERN_INITIALIZER 
                                        | PATTERN_INITIALIZER "," PATTERN_INITIALIZER_LIST
                                        ;
PATTERN_INITIALIZER                     : PATTERN
                                        | PATTERN INITIALIZER
                                        ;
INITIALIZER                             : "←" EXPRESSION
                                        ;

/*
 *  TYPE ALIAS DECLARATION
 */

TYPE_ALIAS_DECLARATION                  : TYPE_ALIAS_DECLARATION_HEAD TYPE_ALIAS_NAME TYPE_ALIAS_ASSIGNMENT {
                                          $$ = new AST::TypeDeclaration($2);
                                        }
                                        | TYPE_ALIAS_DECLARATION_HEAD TYPE_ALIAS_NAME GENERIC_PARAMETER_CLAUSE TYPE_ALIAS_ASSIGNMENT {
                                          $$ = new AST::TypeDeclaration($2);
                                        }
                                        ;
TYPE_ALIAS_DECLARATION_HEAD             : "type"
                                        ;
TYPE_ALIAS_NAME                         : IDENTIFIER
                                        ;
TYPE_ALIAS_ASSIGNMENT                   : "←" TYPE
                                        ;

/*
 *  ENUMERATION DECLARATION
 */

ENUMERATION_DECLARATION                 : ENUMERATION_DECLARATION_HEAD ENUMERATION_DECLARATION_NAME ENUMERATION_DECLARATION_BODY {
                                          $$ = new AST::EnumerationDeclaration($2);
                                        }
                                        | ENUMERATION_DECLARATION_HEAD ENUMERATION_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE ENUMERATION_DECLARATION_BODY {
                                          $$ = new AST::EnumerationDeclaration($2);
                                        }
                                        ;
ENUMERATION_DECLARATION_HEAD            : "enumeration"
                                        ;
ENUMERATION_DECLARATION_NAME            : IDENTIFIER
                                        ;
ENUMERATION_DECLARATION_BODY            : "{" ENUMERATION_DECLARATION_MEMBERS "}"
                                        ;
ENUMERATION_DECLARATION_MEMBERS         : ENUMERATION_DECLARATION_MEMBER
                                        | ENUMERATION_DECLARATION_MEMBER "," ENUMERATION_DECLARATION_MEMBERS
                                        ;
ENUMERATION_DECLARATION_MEMBER          : DECLARATION 
                                        | ENUMERATION_DECLARATION_CASE 
                                        ;
ENUMERATION_DECLARATION_CASE            : ENUMERATION_DECLARATION_CASE_NAME
                                        | ENUMERATION_DECLARATION_CASE_NAME ENUMERATION_DECLARATION_ASSIGNMENT
                                        ;
ENUMERATION_DECLARATION_CASE_NAME       : IDENTIFIER
                                        ;
ENUMERATION_DECLARATION_ASSIGNMENT      : "←" ENUMERATION_DECLARATION_LITERAL
                                        ;
ENUMERATION_DECLARATION_LITERAL         : BOOLEAN_LITERAL 
                                        | NUMERIC_LITERAL
                                        ;

/*
 *  RECORD DECLARATION
 */

RECORD_DECLARATION                      : RECORD_DECLARATION_HEAD RECORD_DECLARATION_NAME RECORD_BODY {
                                          $$ = new AST::RecordDeclaration($2);
                                        }
                                        | RECORD_DECLARATION_HEAD RECORD_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE RECORD_BODY {
                                          $$ = new AST::RecordDeclaration($2);
                                        }
                                        ;
RECORD_DECLARATION_HEAD                 : "record"
                                        ;
RECORD_DECLARATION_NAME                 : IDENTIFIER
                                        ;
RECORD_BODY                             : "{" "}"
                                        | "{" RECORD_MEMBERS "}"
                                        ;
RECORD_MEMBERS                          : RECORD_MEMBER
                                        | RECORD_MEMBER "," RECORD_MEMBERS
                                        ;
RECORD_MEMBER                           : DECLARATION
                                        | RECORD_MEMBER_NAME TYPE_ANNOTATION
                                        ;
RECORD_MEMBER_NAME                      : IDENTIFIER
                                        ;

/*
 *  SUBROUTINE DECLARATION
 */

SUBROUTINE_DECLARATION                  : SUBROUTINE_DECLARATION_HEAD SUBROUTINE_NAME SUBROUTINE_SIGNATURE {
                                          $$ = new AST::SubroutineDeclaration($2);
                                        }
                                        | SUBROUTINE_DECLARATION_HEAD SUBROUTINE_NAME SUBROUTINE_SIGNATURE SUBROUTINE_BODY {
                                          $$ = new AST::SubroutineDeclaration($2);
                                        }
                                        | SUBROUTINE_DECLARATION_HEAD SUBROUTINE_NAME GENERIC_PARAMETER_CLAUSE SUBROUTINE_SIGNATURE {
                                          $$ = new AST::SubroutineDeclaration($2);
                                        }
                                        | SUBROUTINE_DECLARATION_HEAD SUBROUTINE_NAME GENERIC_PARAMETER_CLAUSE SUBROUTINE_SIGNATURE SUBROUTINE_BODY {
                                          $$ = new AST::SubroutineDeclaration($2);
                                        }
                                        ;
SUBROUTINE_DECLARATION_HEAD             : "subroutine"
                                        ;
SUBROUTINE_NAME                         : IDENTIFIER 
                                        ;
SUBROUTINE_SIGNATURE                    : PARAMETER_CLAUSE
                                        | PARAMETER_CLAUSE SUBROUTINE_RESULT
                                        ;
SUBROUTINE_RESULT                       : "→" TYPE
                                        ;
SUBROUTINE_BODY                         : CODE_BLOCK
                                        ;
PARAMETER_CLAUSE                        : "(" ")"
                                        | "(" PARAMETER_LIST ")"
                                        ;
PARAMETER_LIST                          : PARAMETER 
                                        | PARAMETER "," PARAMETER_LIST
                                        ;
PARAMETER                               : LOCAL_PARAMETER_NAME TYPE_ANNOTATION
                                        | LOCAL_PARAMETER_NAME TYPE_ANNOTATION DEFAULT_ARGUMENT_CLAUSE
                                        | LOCAL_PARAMETER_NAME TYPE_ANNOTATION "…"
                                        ;
LOCAL_PARAMETER_NAME                    : IDENTIFIER
                                        ;
DEFAULT_ARGUMENT_CLAUSE                 : "←" EXPRESSION
                                        ;

/*
 *  UNION DECLARATION
 */

UNION_DECLARATION                       : UNION_DECLARATION_HEAD UNION_DECLARATION_NAME UNION_DECLARATION_BODY {
                                          $$ = new AST::UnionDeclaration($2);
                                        }
                                        | UNION_DECLARATION_HEAD UNION_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE UNION_DECLARATION_BODY {
                                          $$ = new AST::UnionDeclaration($2);
                                        }
                                        ;
UNION_DECLARATION_HEAD                  : "union"
                                        ;
UNION_DECLARATION_NAME                  : IDENTIFIER
                                        ;
UNION_DECLARATION_BODY                  : "{" "}"
                                        | "{" UNION_DECLARATION_MEMBERS "}"
                                        ;
UNION_DECLARATION_MEMBERS               : UNION_DECLARATION_MEMBER
                                        | UNION_DECLARATION_MEMBER UNION_DECLARATION_MEMBERS
                                        ;
UNION_DECLARATION_MEMBER                : DECLARATION
                                        | UNION_DECLARATION_CASE_LIST
                                        ;
UNION_DECLARATION_CASE_LIST             : UNION_DECLARATION_CASE 
                                        | UNION_DECLARATION_CASE "," UNION_DECLARATION_CASE_LIST
                                        ;
UNION_DECLARATION_CASE                  : UNION_DECLARATION_CASE_NAME TYPE_ANNOTATION
                                        ;
UNION_DECLARATION_CASE_NAME             : IDENTIFIER
                                        ;

/*
 *  PATTERNS
 */

PATTERN                                 : WILDCARD_PATTERN
                                        | WILDCARD_PATTERN TYPE_ANNOTATION
                                        | IDENTIFIER_PATTERN
                                        | IDENTIFIER_PATTERN TYPE_ANNOTATION
                                        | TUPLE_PATTERN
                                        | TUPLE_PATTERN TYPE_ANNOTATION
                                        | ENUMERATION_DECLARATION_CASE_PATTERN
                                        | TYPE_CASTING_PATTERN
                                        | EXPRESSION_PATTERN
                                        ;

WILDCARD_PATTERN                        : "_"
                                        ;

IDENTIFIER_PATTERN                      : IDENTIFIER
                                        ;

TUPLE_PATTERN                           : "⟨" "⟩"
                                        | "⟨" TUPLE_PATTERN_ELEMENT_LIST "⟩"
                                        ;
TUPLE_PATTERN_ELEMENT_LIST              : TUPLE_PATTERN_ELEMENT
                                        | TUPLE_PATTERN_ELEMENT "," TUPLE_PATTERN_ELEMENT_LIST
                                        ;
TUPLE_PATTERN_ELEMENT                   : PATTERN 
                                        | IDENTIFIER ":" PATTERN
                                        ;

ENUMERATION_DECLARATION_CASE_PATTERN    : "." ENUMERATION_DECLARATION_CASE_NAME 
                                        | "." ENUMERATION_DECLARATION_CASE_NAME TUPLE_PATTERN
                                        | TYPE_IDENTIFIER "." ENUMERATION_DECLARATION_CASE_NAME
                                        | TYPE_IDENTIFIER "." ENUMERATION_DECLARATION_CASE_NAME TUPLE_PATTERN
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

%%

void yy::parser::error(const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
