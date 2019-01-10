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
    #include "type.hh"
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
%type <std::string> PREFIX_OPERATOR;
%type <std::string> CLOSURE_PARAMETER_NAME SUBROUTINE_PARAMETER_NAME;
%type <std::vector<AST::Node*>*> ARRAY_LITERAL_ITEMS TUPLE_LITERAL_ITEMS;
%type <std::vector<AST::Argument*>*> CALL_ARGUMENTS CALL_ARGUMENT_CLAUSE;
%type <std::vector<AST::Parameter*>*> CLOSURE_PARAMETERS CLOSURE_PARAMETER_CLAUSE SUBROUTINE_PARAMETERS PARAMETER_CLAUSE;
%type <AST::Node*> ARRAY_LITERAL_ITEM TUPLE_LITERAL_ITEM EXPRESSION POSTFIX_EXPRESSION;
%type <Type::Type*> TYPE TYPE_ANNOTATION;
%type <Type::Type*> CLOSURE_RETURN_TYPE SUBROUTINE_RETURN_TYPE;
%type <Type::Type*> TYPE_ALIAS_ASSIGNMENT;
%type <AST::Argument*> CALL_ARGUMENT;
%type <AST::ArrayExpression*> ARRAY_LITERAL;
%type <AST::BinaryOperationExpression*> BINARY_EXPRESSION TYPE_CASTING_OPERATOR;
%type <AST::BlockExpression*> BLOCK_EXPRESSION;
%type <AST::BooleanLiteralExpression*> BOOLEAN_LITERAL;
%type <AST::CallExpression*> CALL_EXPRESSION;
%type <AST::ClosureExpression*> CLOSURE_EXPRESSION;
%type <AST::EnumerationDeclaration*> ENUMERATION_DECLARATION;
%type <AST::FloatingPointLiteralExpression*> FLOATING_POINT_LITERAL;
%type <AST::IntegerLiteralExpression*> INTEGER_LITERAL;
%type <AST::Parameter*> CLOSURE_PARAMETER SUBROUTINE_PARAMETER;
%type <AST::UnaryOperationExpression*> PREFIX_EXPRESSION;
%type <AST::SubscriptExpression*> SUBSCRIPT_EXPRESSION;
%type <AST::TupleExpression*> TUPLE_LITERAL;
%type <AST::TypeAliasDeclaration*> TYPE_ALIAS_DECLARATION;
%type <AST::TypeSignature*> CLOSURE_SIGNATURE SUBROUTINE_SIGNATURE;
%type <AST::ForLoopExpression*> FOR_IN_STATEMENT;
%type <AST::WhileLoopExpression*> WHILE_STATEMENT;
%type <Pattern::Pattern*> PATTERN;

/*
 *
 */

%type <AST::BreakExpression*> BREAK_STATEMENT;
%type <AST::ContinueExpression*> CONTINUE_STATEMENT;
%type <AST::ConditionalExpression*> IF_STATEMENT;
%type <AST::LabelStatement*> LABELED_STATEMENT
%type <AST::Node*> LOOP_STATEMENT;
%type <AST::Node*> STATEMENT;
%type <AST::ReturnExpression*> RETURN_STATEMENT;
%type <AST::Root*> ROOT;
%type <AST::SwitchExpression*> SWITCH_STATEMENT;
%type <std::string> LABEL_NAME;
%type <AST::LabelStatement*> STATEMENT_LABEL;
%type <std::vector<AST::Node*>*> STATEMENTS;

%type <AST::SubroutineDeclaration*> SUBROUTINE_DECLARATION;
%type <AST::Node*> DEFAULT_ARGUMENT_CLAUSE;

%type <AST::RecordDeclaration*> RECORD_DECLARATION;
%type <std::vector<AST::RecordFieldDeclaration*>*> RECORD_BODY;
%type <std::vector<AST::RecordFieldDeclaration*>*> RECORD_FIELDS;
%type <AST::RecordFieldDeclaration*> RECORD_FIELD;
%type <std::string> RECORD_FIELD_NAME;

%type <AST::UnionDeclaration*> UNION_DECLARATION;
%type <std::vector<AST::RecordFieldDeclaration*>*> UNION_DECLARATION_BODY;

%%

%start ROOT;

ROOT                                    : {
                                          $$ = new AST::Root();

                                          compiler.root = $$;
                                        }
                                        | STATEMENTS {
                                          $$ = new AST::Root($1);

                                          compiler.root = $$;
                                        }
                                        ;

EXPRESSION                              : PREFIX_EXPRESSION 
                                        | PREFIX_EXPRESSION BINARY_EXPRESSIONS
                                        ;
PREFIX_EXPRESSION                       : POSTFIX_EXPRESSION {
                                          $$ = new AST::UnaryOperationExpression($1);
                                        }
                                        | PREFIX_OPERATOR POSTFIX_EXPRESSION {
                                          $$ = new AST::UnaryOperationExpression($1, $2);
                                        }
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
TYPE_ANNOTATION                         : ":" TYPE {
                                          $$ = $2;
                                        }
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
BOOLEAN_LITERAL                         : "true" {
                                          $$ = new AST::BooleanLiteralExpression(true);
                                        }
                                        | "false" {
                                          $$ = new AST::BooleanLiteralExpression(false);
                                        }
                                        ;
NUMERIC_LITERAL                         : FLOATING_POINT_LITERAL
                                        | INTEGER_LITERAL
                                        ;
FLOATING_POINT_LITERAL                  : FLOATING_POINT {
                                          $$ = new AST::FloatingPointLiteralExpression($1);
                                        }
                                        | "−" FLOATING_POINT  %prec UNARY_MINUS_SIGN {
                                          $$ = new AST::FloatingPointLiteralExpression($2);
                                        }
                                        ;
INTEGER_LITERAL                         : INTEGER {
                                          $$ = new AST::IntegerLiteralExpression($1);
                                        }
                                        | "−" INTEGER         %prec UNARY_MINUS_SIGN {
                                          $$ = new AST::IntegerLiteralExpression($2);
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
CLOSURE_EXPRESSION                      : CLOSURE_HEAD CLOSURE_SIGNATURE BLOCK_EXPRESSION {
                                          $$ = new AST::ClosureExpression($2, $3);
                                        }
                                        | CLOSURE_HEAD BLOCK_EXPRESSION {
                                          $$ = new AST::ClosureExpression($2);
                                        }
                                        ;
CLOSURE_HEAD                            : "λ"
                                        ;
CLOSURE_SIGNATURE                       : CLOSURE_PARAMETER_CLAUSE {
                                          $$ = new AST::TypeSignature($1);
                                        }
                                        | CLOSURE_PARAMETER_CLAUSE CLOSURE_RETURN_TYPE {
                                          $$ = new AST::TypeSignature($1, $2);
                                        }
                                        ;
CLOSURE_PARAMETER_CLAUSE                : "(" CLOSURE_PARAMETERS ")" 
                                        ;
CLOSURE_PARAMETERS                      : %empty
                                        | CLOSURE_PARAMETER {
                                          $$ = new std::vector<AST::Parameter*>();

                                          $$ -> push_back($1);
                                        }
                                        | CLOSURE_PARAMETER "," CLOSURE_PARAMETERS {
                                          std::vector<AST::Parameter*> *parameters = $3;

                                          parameters -> push_back($1);

                                          $$ = parameters;                                           
                                        }
                                        ;
CLOSURE_PARAMETER                       : CLOSURE_PARAMETER_NAME {
                                          $$ = new AST::Parameter($1);
                                        }
                                        | CLOSURE_PARAMETER_NAME TYPE_ANNOTATION {
                                          $$ = new AST::Parameter($1, $2);
                                        }
                                        | CLOSURE_PARAMETER_NAME TYPE_ANNOTATION "…" {
                                          $$ = new AST::Parameter($1, $2);
                                        }
                                        ;
CLOSURE_PARAMETER_NAME                  : IDENTIFIER
                                        ;
CLOSURE_RETURN_TYPE                     : "→" TYPE {
                                          $$ = $2;
                                        }
BLOCK_EXPRESSION                        : "{" "}" {
                                          $$ = new AST::BlockExpression();
                                        }
                                        | "{" STATEMENTS "}" {
                                          $$ = new AST::BlockExpression($2);
                                        }
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
CALL_EXPRESSION                         : POSTFIX_EXPRESSION CALL_ARGUMENT_CLAUSE {
                                          $$ = new AST::CallExpression($1, $2);
                                        }
                                        ;
CALL_ARGUMENT_CLAUSE                    : "(" ")"
                                        | "(" CALL_ARGUMENTS ")"
                                        ;
CALL_ARGUMENTS                          : CALL_ARGUMENT {
                                          $$ = new std::vector<AST::Argument*>();

                                          $$ -> push_back($1);
                                        }
                                        | CALL_ARGUMENT "," CALL_ARGUMENTS {
                                          std::vector<AST::Argument*> *arguments = $3;

                                          arguments -> push_back($1);

                                          $$ = arguments;
                                        }
                                        ;
CALL_ARGUMENT                           : EXPRESSION {
                                          $$ = new AST::Argument($1);
                                        }
                                        | IDENTIFIER ":" EXPRESSION {
                                          $$ = new AST::Argument($1, $3);
                                        }
                                        ;
SUBSCRIPT_EXPRESSION                    : POSTFIX_EXPRESSION "[" CALL_ARGUMENTS "]" {
                                          $$ = new AST::SubscriptExpression($1, $3);
                                        }
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

SUBROUTINE_DECLARATION                  : SUBROUTINE_DECLARATION_HEAD SUBROUTINE_NAME SUBROUTINE_SIGNATURE {
                                          $$ = new AST::SubroutineDeclaration($2, $3);
                                        }
                                        | SUBROUTINE_DECLARATION_HEAD SUBROUTINE_NAME SUBROUTINE_SIGNATURE SUBROUTINE_BODY {
                                          $$ = new AST::SubroutineDeclaration($2, $3);
                                        }
                                        | SUBROUTINE_DECLARATION_HEAD SUBROUTINE_NAME GENERIC_PARAMETER_CLAUSE SUBROUTINE_SIGNATURE {
                                          $$ = new AST::SubroutineDeclaration($2, $4);
                                        }
                                        | SUBROUTINE_DECLARATION_HEAD SUBROUTINE_NAME GENERIC_PARAMETER_CLAUSE SUBROUTINE_SIGNATURE SUBROUTINE_BODY {
                                          $$ = new AST::SubroutineDeclaration($2, $4);
                                        }
                                        ;
SUBROUTINE_DECLARATION_HEAD             : "subroutine"
                                        ;
SUBROUTINE_NAME                         : IDENTIFIER 
                                        ;
SUBROUTINE_SIGNATURE                    : PARAMETER_CLAUSE {
                                          $$ = new AST::TypeSignature($1);
                                        }
                                        | PARAMETER_CLAUSE SUBROUTINE_RETURN_TYPE {
                                          $$ = new AST::TypeSignature($1, $2);
                                        }
                                        ;
SUBROUTINE_RETURN_TYPE                  : "→" TYPE {
                                          $$ = $2;
                                        }
                                        ;
SUBROUTINE_BODY                         : BLOCK_EXPRESSION
                                        ;
PARAMETER_CLAUSE                        : "(" SUBROUTINE_PARAMETERS ")"
                                        ;
SUBROUTINE_PARAMETERS                   : %empty
                                        | SUBROUTINE_PARAMETER {
                                            $$ = new std::vector<AST::Parameter*>();

                                            $$ -> push_back($1);
                                        }
                                        | SUBROUTINE_PARAMETER "," SUBROUTINE_PARAMETERS {
                                          std::vector<AST::Parameter*> *parameters = $3;

                                          parameters -> push_back($1);

                                          $$ = parameters;   
                                        }
                                        ;
SUBROUTINE_PARAMETER                    : SUBROUTINE_PARAMETER_NAME TYPE_ANNOTATION {
                                          $$ = new AST::Parameter($1, $2);
                                        }
                                        | SUBROUTINE_PARAMETER_NAME TYPE_ANNOTATION DEFAULT_ARGUMENT_CLAUSE {
                                          $$ = new AST::Parameter($1, $2);
                                        }
                                        | SUBROUTINE_PARAMETER_NAME TYPE_ANNOTATION "…" {
                                          $$ = new AST::Parameter($1, $2);
                                        }
                                        ;
SUBROUTINE_PARAMETER_NAME               : IDENTIFIER
                                        ;
DEFAULT_ARGUMENT_CLAUSE                 : "←" EXPRESSION {
                                          $$ = $2;
                                        }
                                        ;

/*
 *  2.2   TYPE ALIAS
 */

TYPE_ALIAS_DECLARATION                  : TYPE_ALIAS_DECLARATION_HEAD TYPE_ALIAS_NAME TYPE_ALIAS_ASSIGNMENT {
                                          $$ = new AST::TypeAliasDeclaration($2, $3);
                                        }
                                        | TYPE_ALIAS_DECLARATION_HEAD TYPE_ALIAS_NAME GENERIC_PARAMETER_CLAUSE TYPE_ALIAS_ASSIGNMENT {
                                          $$ = new AST::TypeAliasDeclaration($2, $4);
                                        }
                                        ;
TYPE_ALIAS_DECLARATION_HEAD             : "type"
                                        ;
TYPE_ALIAS_NAME                         : IDENTIFIER
                                        ;
TYPE_ALIAS_ASSIGNMENT                   : "←" TYPE {
                                          $$ = $2;
                                        }
                                        ;

/*
 *  2.3   RECORD 
 */

RECORD_DECLARATION                      : RECORD_DECLARATION_HEAD RECORD_DECLARATION_NAME RECORD_BODY {
                                          $$ = new AST::RecordDeclaration($2, $3);
                                        }
                                        | RECORD_DECLARATION_HEAD RECORD_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE RECORD_BODY {
                                          $$ = new AST::RecordDeclaration($2, $4);
                                        }
                                        ;
RECORD_DECLARATION_HEAD                 : "record"
                                        ;
RECORD_DECLARATION_NAME                 : IDENTIFIER
                                        ;
RECORD_BODY                             : "{" RECORD_FIELDS "}" {
                                          $$ = $2;
                                        }
                                        ;
RECORD_FIELDS                           : %empty {
                                          $$ = new std::vector<AST::RecordFieldDeclaration*>();
                                        }
                                        | RECORD_FIELD {
                                          $$ = new std::vector<AST::RecordFieldDeclaration*>();

                                          $$ -> push_back($1);
                                        }
                                        | RECORD_FIELD "," RECORD_FIELDS {
                                          std::vector<AST::RecordFieldDeclaration*> *fields = $3;

                                          fields -> push_back($1);

                                          $$ = fields;
                                        }
                                        ;
RECORD_FIELD                            : RECORD_FIELD_NAME TYPE_ANNOTATION {
                                          $$ = new AST::RecordFieldDeclaration($1, $2);
                                        }
                                        ;
RECORD_FIELD_NAME                       : IDENTIFIER
                                        ;

/*
 *  2.4   ENUMERATION 
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

UNION_DECLARATION                       : UNION_DECLARATION_HEAD UNION_DECLARATION_NAME UNION_DECLARATION_BODY {
                                          $$ = new AST::UnionDeclaration($2, $3);
                                        }
                                        | UNION_DECLARATION_HEAD UNION_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE UNION_DECLARATION_BODY {
                                          $$ = new AST::UnionDeclaration($2, $4);
                                        }
                                        ;
UNION_DECLARATION_HEAD                  : "union"
                                        ;
UNION_DECLARATION_NAME                  : IDENTIFIER
                                        ;
UNION_DECLARATION_BODY                  : "{" RECORD_FIELDS "}" {
                                          $$ = $2;
                                        }
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
 *  3.0   STATEMENTS
 */

STATEMENTS                              : STATEMENT {
                                          $$ = new std::vector<AST::Node*>();

                                          $$ -> push_back($1);
                                        }
                                        | STATEMENT STATEMENTS {
                                          std::vector<AST::Node*> *statements = $2;

                                          statements -> push_back($1);

                                          $$ = statements;  
                                        }
                                        ;
STATEMENT                               : DECLARATION ";"
                                        | EXPRESSION ";"
                                        | LOOP_STATEMENT ";"
                                        | BRANCH_STATEMENT ";"
                                        | LABELED_STATEMENT ";"
                                        | CONTROL_TRANSFER_STATEMENT ";"
                                        ;

/*
 *  4.0   EXPRESSIONS
 */





LOOP_STATEMENT                          : FOR_IN_STATEMENT
                                        | WHILE_STATEMENT
                                        ;
FOR_IN_STATEMENT                        : "for" PATTERN "in" EXPRESSION BLOCK_EXPRESSION {
                                          $$ = new AST::ForLoopExpression($2, $4, $5);
                                        }
                                        ;
WHILE_STATEMENT                         : "WhileLoopExpression" EXPRESSION BLOCK_EXPRESSION {
                                          $$ = new AST::WhileLoopExpression($2, $3);
                                        }
                                        ;
BRANCH_STATEMENT                        : IF_STATEMENT
                                        | SWITCH_STATEMENT
                                        ;
IF_STATEMENT                            : "if" CONDITION_LIST BLOCK_EXPRESSION {
                                          $$ = new AST::ConditionalExpression();
                                        }
                                        | "if" CONDITION_LIST BLOCK_EXPRESSION ELSE_CLAUSE {
                                          $$ = new AST::ConditionalExpression();
                                        }
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
SWITCH_STATEMENT                        : "switch" EXPRESSION "{" "}" {
                                          $$ = new AST::SwitchExpression();
                                        }
                                        | "switch" EXPRESSION "{" SWITCH_CASES "}" {
                                          $$ = new AST::SwitchExpression();
                                        }
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
STATEMENT_LABEL                         : LABEL_NAME ":" {
                                          $$ = new AST::LabelStatement($1);
                                        }
                                        ;
LABEL_NAME                              : IDENTIFIER
                                        ;
CONTROL_TRANSFER_STATEMENT              : BREAK_STATEMENT
                                        | CONTINUE_STATEMENT
                                        | RETURN_STATEMENT
                                        ;
BREAK_STATEMENT                         : "break" {
                                          $$ = new AST::BreakExpression();
                                        }
                                        | "break" LABEL_NAME {
                                          $$ = new AST::BreakExpression($2);
                                        }
                                        ;
CONTINUE_STATEMENT                      : "continue" {
                                          $$ = new AST::ContinueExpression();
                                        }
                                        | "continue" LABEL_NAME {
                                          $$ = new AST::ContinueExpression($2);
                                        }
                                        ;
RETURN_STATEMENT                        : "return" {
                                          $$ = new AST::ReturnExpression();
                                        }
                                        | "return" EXPRESSION {
                                          $$ = new AST::ReturnExpression($2);
                                        }
                                        ;

%%

void yy::parser::error(const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
