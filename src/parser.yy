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
    #include "include/variant.hh"
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

/*
 *  TYPES
 */

%type <std::shared_ptr<AST::Type>>                  TYPE;


/*
 *  EXPRESSIONS
 */

/*
 *  ARRAY EXPRESSION
 */

%type <std::shared_ptr<Expression::Array>>          ARRAY_EXPRESSION;

/*
 *  TUPLE EXPRESSION
 */

%type <std::shared_ptr<Expression::Tuple>>          TUPLE_EXPRESSION;

/*
 *  TAGGED UNION DECLARATION
 */

%type <std::shared_ptr<Declaration::TaggedUnion>>   TAGGED_UNION_DECLARATION;
%type <AST::Identifier>                             TAGGED_UNION_DECLARATION_NAME;
%type <std::vector<std::shared_ptr<AST::Variant>>>  TAGGED_UNION_DECLARATION_BODY;
%type <std::vector<std::shared_ptr<AST::Variant>>>  TAGGED_UNION_DECLARATION_TAGS;
%type <std::shared_ptr<AST::Variant>>               TAGGED_UNION_DECLARATION_TAG;

/*
 *  VARIANTS
 */

%type <std::shared_ptr<AST::Variant>>               VARIANT;

/*
 *  RECORD VARIANT
 */

%type <std::shared_ptr<Variant::Record>>            VARIANT_RECORD;
%type <AST::Identifier>                             VARIANT_RECORD_NAME;
%type <std::vector<AST::RecordField>>               VARIANT_RECORD_BODY;
%type <std::vector<AST::RecordField>>               VARIANT_RECORD_FIELDS;
%type <AST::RecordField>                            VARIANT_RECORD_FIELD;
%type <AST::Identifier>                             VARIANT_RECORD_FIELD_NAME;
%type <std::shared_ptr<AST::Type>>                  VARIANT_RECORD_FIELD_TYPE;

/*
 *  TUPLE VARIANT
 */

%type <std::shared_ptr<Variant::Tuple>>             VARIANT_TUPLE;
%type <AST::Identifier>                             VARIANT_TUPLE_NAME;
%type <std::vector<AST::RecordField>>               VARIANT_TUPLE_BODY;
%type <std::vector<AST::RecordField>>               VARIANT_TUPLE_FIELDS;
%type <AST::RecordField>                            VARIANT_TUPLE_FIELD;
%type <std::shared_ptr<AST::Type>>                  VARIANT_TUPLE_FIELD_TYPE;

/*
 *  UNIT VARIANT
 */

%type <std::shared_ptr<Variant::Unit>>              VARIANT_UNIT;

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

%start STATEMENTS;

/*
 *  TYPES
 */

TYPE                              : TYPE_ARRAY
                                  | TYPE_IDENTIFIER
                                  | TYPE_TUPLE
                                  | TYPE_PRIMITIVE
                                  ;
TYPE_ARRAY                        : "[" EXPRESSION "×" TYPE "]"
                                  ;
TYPE_IDENTIFIER                   : TYPE_NAME
                                  ;
TYPE_NAME                         : IDENTIFIER
                                  ;
TYPE_TUPLE                        : "⟨" TYPE_TUPLE_ELEMENTS "⟩"
                                  ;
TYPE_TUPLE_ELEMENTS               : TYPE_TUPLE_ELEMENT 
                                  | TYPE_TUPLE_ELEMENT "×" TYPE_TUPLE_ELEMENTS
                                  ;
TYPE_TUPLE_ELEMENT                : TYPE
                                  ;
TYPE_PRIMITIVE                    : TYPE_BOOLEAN
                                  | TYPE_FLOATING_POINT
                                  | TYPE_INTEGER
                                  ;
TYPE_BOOLEAN                      : "Boolean"
                                  ;
TYPE_FLOATING_POINT               : TYPE_FLOATING_POINT_SIZE "Floating-point"
                                  ;
TYPE_FLOATING_POINT_SIZE          : "16-bit"
                                  | "32-bit"
                                  | "64-bit"
                                  ;
TYPE_INTEGER                      : TYPE_INTEGER_SIGNEDNESS TYPE_INTEGER_SIZE "Integer"
                                  ;
TYPE_INTEGER_SIZE                 :   "8-bit"
                                  |  "16-bit"
                                  |  "32-bit"
                                  |  "64-bit"
                                  | "128-bit"
                                  ;
TYPE_INTEGER_SIGNEDNESS           : 
                                  | "unsigned"
                                  ;

/*
 *  EXPRESSIONS
 */

EXPRESSION                        : LITERAL_EXPRESSION
                                  | TUPLE_EXPRESSION
                                  ;

/*
 *  ARRAY EXPRESSION
 */

ARRAY_EXPRESSION                  : "[" ARRAY_EXPRESSION_ELEMENTS "]"
                                  ;
ARRAY_EXPRESSION_ELEMENTS         :
                                  | ARRAY_EXPRESSION_ELEMENT
                                  | ARRAY_EXPRESSION_ELEMENT "," ARRAY_EXPRESSION_ELEMENTS
                                  ;
ARRAY_EXPRESSION_ELEMENT          : EXPRESSION
                                  ;

/*
 *  LITERAL EXPRESSION
 */

LITERAL_EXPRESSION                : LITERAL_EXPRESSION_BOOLEAN 
                                  | LITERAL_EXPRESSION_FLOATING_POINT
                                  | LITERAL_EXPRESSION_INTEGER
                                  ;
LITERAL_EXPRESSION_BOOLEAN        : "true"
                                  | "false"
                                  ;
LITERAL_EXPRESSION_FLOATING_POINT : FLOATING_POINT
                                  | "−" FLOATING_POINT
                                  ;
LITERAL_EXPRESSION_INTEGER        : INTEGER
                                  | "−" INTEGER
                                  ;

/*
 *  TUPLE EXPRESSION
 */

TUPLE_EXPRESSION                  : "⟨" TUPLE_EXPRESSION_ELEMENTS "⟩"
                                  ;
TUPLE_EXPRESSION_ELEMENTS         :
                                  | TUPLE_EXPRESSION_ELEMENT
                                  | TUPLE_EXPRESSION_ELEMENT "," TUPLE_EXPRESSION_ELEMENTS
                                  ;
TUPLE_EXPRESSION_ELEMENT          : EXPRESSION
                                  | IDENTIFIER ":" EXPRESSION
                                  ;

/*
 *  STATEMENTS
 */

STATEMENTS                        : STATEMENT
                                  | STATEMENT STATEMENTS
                                  ;
STATEMENT                         : DECLARATION ";"
                                  ;

/*
 *  DECLARATIONS
 */

DECLARATION                       : TAGGED_UNION_DECLARATION
                                  ;

/*
 *  TAGGED UNION DECLARATION
 */

TAGGED_UNION_DECLARATION          : "union" TAGGED_UNION_DECLARATION_NAME TAGGED_UNION_DECLARATION_BODY
                                  ;
TAGGED_UNION_DECLARATION_NAME     : IDENTIFIER {
                                    $$ = AST::Identifier($1);
                                  }
                                  ;
TAGGED_UNION_DECLARATION_BODY     : "{" TAGGED_UNION_DECLARATION_TAGS "}" {
                                    $$ = $2;
                                  }
                                  ;
TAGGED_UNION_DECLARATION_TAGS     : %empty {
                                    $$ = std::vector<std::shared_ptr<AST::Variant>>();
                                  }
                                  | TAGGED_UNION_DECLARATION_TAG {
                                    $$ = std::vector<std::shared_ptr<AST::Variant>>();

                                    $$.push_back($1);
                                  }
                                  | TAGGED_UNION_DECLARATION_TAG "," TAGGED_UNION_DECLARATION_TAGS {
                                    std::vector<std::shared_ptr<AST::Variant>> tags = $3;

                                    tags.push_back($1);

                                    $$ = tags;
                                  }
                                  ;
TAGGED_UNION_DECLARATION_TAG      : VARIANT
                                  ;

/*
 *  VARIANTS
 */

VARIANT                           : VARIANT_RECORD
                                  | VARIANT_TUPLE
                                  ;

/*
 *  RECORD VARIANT
 */

VARIANT_RECORD                    : VARIANT_RECORD_NAME VARIANT_RECORD_BODY {
                                    std::shared_ptr<Variant::Record> variant (new Variant::Record($1, $2));

                                    $$ = variant;
                                  }
                                  ;
VARIANT_RECORD_NAME               : IDENTIFIER ":" {
                                    $$ = AST::Identifier($1);
                                  }
                                  ;
VARIANT_RECORD_BODY               : "{" VARIANT_RECORD_FIELDS "}" {
                                    $$ = $2;
                                  }
                                  ;
VARIANT_RECORD_FIELDS             : %empty {
                                    $$ = std::vector<AST::RecordField>();
                                  }
                                  | VARIANT_RECORD_FIELD {
                                    $$ = std::vector<AST::RecordField>();

                                    $$.push_back($1);
                                  }
                                  | VARIANT_RECORD_FIELD "," VARIANT_RECORD_FIELDS {
                                    std::vector<AST::RecordField> fields = $3;

                                    fields.push_back($1);

                                    $$ = fields;
                                  }
                                  ;
VARIANT_RECORD_FIELD              : VARIANT_RECORD_FIELD_NAME VARIANT_RECORD_FIELD_TYPE {}
                                  ;
VARIANT_RECORD_FIELD_NAME         : IDENTIFIER ":" {
                                    $$ = AST::Identifier($1);
                                  }
                                  ;
VARIANT_RECORD_FIELD_TYPE         : TYPE
                                  ;

/*
 *  TUPLE VARIANT
 */

VARIANT_TUPLE                     : VARIANT_TUPLE_NAME VARIANT_TUPLE_BODY {
                                    std::shared_ptr<Variant::Tuple> variant (new Variant::Tuple($1, $2));

                                    $$ = variant;
                                  }
                                  ;
VARIANT_TUPLE_NAME                : IDENTIFIER ":" {
                                    $$ = AST::Identifier($1);
                                  }
                                  ;
VARIANT_TUPLE_BODY                : "⟨" VARIANT_TUPLE_FIELDS "⟩" {
                                    $$ = $2;
                                  }
                                  ;
VARIANT_TUPLE_FIELDS              : %empty {
                                    $$ = std::vector<AST::RecordField>();
                                  }
                                  | VARIANT_TUPLE_FIELD {
                                    $$ = std::vector<AST::RecordField>();

                                    $$.push_back($1);
                                  }
                                  | VARIANT_TUPLE_FIELD "×" VARIANT_TUPLE_FIELDS {
                                    std::vector<AST::RecordField> fields = $3;

                                    fields.push_back($1);

                                    $$ = fields;
                                  }
                                  ;
VARIANT_TUPLE_FIELD               : VARIANT_TUPLE_FIELD_TYPE {
                                    $$ = AST::RecordField($1);
                                  }
                                  ;
VARIANT_TUPLE_FIELD_TYPE          : TYPE
                                  ;

/*
 *  UNIT VARIANT
 */

VARIANT_UNIT                      : IDENTIFIER {
                                    $$ = AST::Identifier($1);
                                  }
                                  ;

%%

void yy::parser::error(const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
