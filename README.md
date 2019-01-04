# Ox

## Syntax

	/*
	 *  TYPES
	 */

	TYPE                            : ARRAY_TYPE
	                                | ASSOCIATIVE_ARRAY_TYPE
	                                | FUNCTION_TYPE
	                                | TYPE_IDENTIFIER
	                                | TUPLE_TYPE
	                                | OPTIONAL_TYPE
	                                | "Any"
	                                | "(" TYPE ")"
	                                ;

	ASSOCIATIVE_ARRAY_TYPE          : "{" TYPE ":" TYPE "}"
	                                ;

	TYPE_ANNOTATION                 : ":" TYPE
	                                ;

	OPTIONAL_TYPE                   : TYPE "?"
	                                ;

	/*
	 *  EXPRESSIONS
	 */

	EXPRESSION                      : PREFIX_EXPRESSION 
	                                | PREFIX_EXPRESSION BINARY_EXPRESSIONS
	                                ;
	PREFIX_EXPRESSION               : POSTFIX_EXPRESSION
	                                | PREFIX_OPERATOR POSTFIX_EXPRESSION
	                                ;

	BINARY_EXPRESSION               : BINARY_OPERATOR PREFIX_EXPRESSION
	                                | ASSIGNMENT_OPERATOR PREFIX_EXPRESSION
	                                | TYPE_CASTING_OPERATOR
	                                ;
	                                
	BINARY_EXPRESSIONS              : BINARY_EXPRESSION 
	                                | BINARY_EXPRESSION BINARY_EXPRESSIONS
	                                ;

	ASSIGNMENT_OPERATOR             : "←"
	                                ;

	TYPE_CASTING_OPERATOR           : "is" TYPE
	                                | "as" TYPE
	                                ;

	EXPRESSIONS                     : EXPRESSION
	                                | EXPRESSION "," EXPRESSIONS
	                                ;

	PRIMARY_EXPRESSION              : LITERAL_EXPRESSION
	                                | CLOSURE_EXPRESSION
	                                | PARENTHESIZED_EXPRESSION
	                                | WILDCARD_EXPRESSION
	                                | EXPLICIT_MEMBER_EXPRESSION
	                                ;

	LITERAL_EXPRESSION              : LITERAL
	                                | ARRAY_LITERAL
	                                | ASSOCIATIVE_ARRAY_LITERAL
	                                | TUPLE_LITERAL
	                                ;

	ARRAY_LITERAL                   : "[" ARRAY_LITERAL_ITEMS "]"
	                                ;
	ARRAY_LITERAL_ITEMS             : ARRAY_LITERAL_ITEM 
	                                | ARRAY_LITERAL_ITEM "," ARRAY_LITERAL_ITEMS
	                                ;
	ARRAY_LITERAL_ITEM              : EXPRESSION
	                                ;

	ASSOCIATIVE_ARRAY_LITERAL       : "{" ASSOCIATIVE_ARRAY_LITERAL_ITEMS "}"
	                                ;
	ASSOCIATIVE_ARRAY_LITERAL_ITEMS : ASSOCIATIVE_ARRAY_LITERAL_ITEM 
	                                | ASSOCIATIVE_ARRAY_LITERAL_ITEM "," ASSOCIATIVE_ARRAY_LITERAL_ITEMS
	                                ;
	ASSOCIATIVE_ARRAY_LITERAL_ITEM  : EXPRESSION ":" EXPRESSION
	                                ;

	TUPLE_LITERAL                   : "⟨" "⟩" 
	                                | "⟨" TUPLE_LITERAL_ITEM "," TUPLE_LITERAL_ITEMS "⟩"
	                                ;
	TUPLE_LITERAL_ITEMS             : TUPLE_LITERAL_ITEM 
	                                | TUPLE_LITERAL_ITEM "," TUPLE_LITERAL_ITEMS
	                                ;
	TUPLE_LITERAL_ITEM              : EXPRESSION
	                                | IDENTIFIER ":" EXPRESSION
	                                ;

	PARENTHESIZED_EXPRESSION        : "(" EXPRESSION ")"
	                                ;

	WILDCARD_EXPRESSION             : "_"
	                                ;

	POSTFIX_EXPRESSION              : PRIMARY_EXPRESSION
	                                | POSTFIX_EXPRESSION POSTFIX_OPERATOR
	                                | FUNCTION_CALL_EXPRESSION
	                                | SUBSCRIPT_EXPRESSION
	                                ;

	FUNCTION_CALL_EXPRESSION        : POSTFIX_EXPRESSION FUNCTION_CALL_ARGUMENT_CLAUSE
	                                ;
	FUNCTION_CALL_ARGUMENT_CLAUSE   : "(" ")" 
	                                | "(" FUNCTION_CALL_ARGUMENT_LIST ")"
	                                ;
	FUNCTION_CALL_ARGUMENT_LIST     : FUNCTION_CALL_ARGUMENT 
	                                | FUNCTION_CALL_ARGUMENT "," FUNCTION_CALL_ARGUMENT_LIST
	                                ;
	FUNCTION_CALL_ARGUMENT          : EXPRESSION 
	                                | IDENTIFIER ":" EXPRESSION
	                                ;

	SUBSCRIPT_EXPRESSION            : POSTFIX_EXPRESSION "[" FUNCTION_CALL_ARGUMENT_LIST "]"
	                                ;

	EXPLICIT_MEMBER_EXPRESSION      : POSTFIX_EXPRESSION "." IDENTIFIER
	                                | POSTFIX_EXPRESSION "." IDENTIFIER GENERIC_ARGUMENT_CLAUSE
	                                | POSTFIX_EXPRESSION "." IDENTIFIER "(" ARGUMENT_NAMES ")"
	                                ;
	ARGUMENT_NAMES                  : ARGUMENT_NAME
	                                | ARGUMENT_NAME ARGUMENT_NAMES
	                                ;                                
	ARGUMENT_NAME                   : IDENTIFIER ":"
	                                ;

	/*
	 *  STATEMENTS
	 */

	STATEMENT                       : EXPRESSION ";"
	                                | DECLARATION ";"
	                                | LOOP_STATEMENT ";"
	                                | BRANCH_STATEMENT ";"
	                                | LABELED_STATEMENT ";"
	                                | CONTROL_TRANSFER_STATEMENT ";"
	                                ;

	LOOP_STATEMENT                  : FOR_IN_STATEMENT
	                                | WHILE_STATEMENT
	                                ;

	FOR_IN_STATEMENT                : "for" PATTERN "IN" EXPRESSION CODE_BLOCK
	                                ;

	WHILE_STATEMENT                 : "while" CONDITION_LIST CODE_BLOCK
	                                ;
	CONDITION_LIST                  : CONDITION 
	                                | CONDITION "," CONDITION_LIST

	CONDITION                       : EXPRESSION 
	                                | CASE_CONDITION
	                                ;
	CASE_CONDITION                  : "case" PATTERN INITIALIZER
	                                ;

	branch_statement                : if_statement
	                                | switch_statement
	                                ;

	IF_STATEMENT                    : "if" CONDITION_LIST CODE_BLOCK ELSE_CLAUSE OPT
	                                ;
	ELSE_CLAUSE                     : "else" CODE_BLOCK 
	                                | "else" IF_STATEMENT
	                                ;

	SWITCH_STATEMENT                : "switch" EXPRESSION "{" "}"
	                                | "switch" EXPRESSION "{" SWITCH_CASES "}"
	                                ;
	SWITCH_CASES                    : SWITCH_CASE 
	                                | SWITCH_CASE SWITCH_CASES
	                                ;
	SWITCH_CASE                     : CASE_LABEL STATEMENTS
	                                | DEFAULT_LABEL STATEMENTS
	                                ;
	CASE_LABEL                      : "case" CASE_ITEM_LIST ":"
	                                ;
	CASE_ITEM_LIST                  : PATTERN
	                                | PATTERN WHERE_CLAUSE 
	                                | PATTERN "," CASE_ITEM_LIST
	                                | PATTERN WHERE_CLAUSE "," CASE_ITEM_LIST
	                                ;
	DEFAULT_LABEL                   : "default" ":"
	                                ;
	WHERE_CLAUSE                    : "where" WHERE_EXPRESSION
	                                ;
	WHERE_EXPRESSION                : EXPRESSION
	                                ;

	LABELED_STATEMENT               : STATEMENT_LABEL LOOP_STATEMENT
	                                | STATEMENT_LABEL IF_STATEMENT
	                                | STATEMENT_LABEL SWITCH_STATEMENT
	                                | STATEMENT_LABEL DO_STATEMENT
	                                | LABEL_NAME ":"
	                                ;
	LABEL_NAME                      : IDENTIFIER
	                                ;

	CONTROL_TRANSFER_STATEMENT      : BREAK_STATEMENT
	                                | CONTINUE_STATEMENT
	                                | RETURN_STATEMENT
	                                ;

	BREAK_STATEMENT                 : "break"
	                                | "break" LABEL_NAME 
	                                ;

	CONTINUE_STATEMENT              : "continue"
	                                | "continue" LABEL_NAME
	                                ;

	RETURN_STATEMENT                : "return"
	                                | "return" EXPRESSION
	                                ;

	/*
	 *  DECLARATIONS
	 */

	DECLARATION                     : CONSTANT_DECLARATION
	                                | VARIABLE_DECLARATION
	                                | TYPE_ALIAS_DECLARATION
	                                | FUNCTION_DECLARATION
	                                | UNION_DECLARATION
	                                | ENUM_DECLARATION
	                                | STRUCT_DECLARATION
	                                ;

	TOP_LEVEL_DECLARATION           : 
	                                | STATEMENTS
	                                ;

	CODE_BLOCK                      : "{" "}"
	                                | "{" STATEMENTS "}"
	                                ;

	CONSTANT_DECLARATION            : "constant" PATTERN_INITIALIZER_LIST
	                                ;
	PATTERN_INITIALIZER_LIST        : PATTERN_INITIALIZER 
	                                | PATTERN_INITIALIZER "," PATTERN_INITIALIZER_LIST
	                                ;
	PATTERN_INITIALIZER             : PATTERN
	                                | PATTERN INITIALIZER
	                                ;
	INITIALIZER                     : "←" EXPRESSION
	                                ;

	TYPE_ALIAS_DECLARATION          : "type" TYPE_ALIAS_NAME TYPE_ALIAS_ASSIGNMENT
	                                | "type" TYPE_ALIAS_NAME GENERIC_PARAMETER_CLAUSE TYPE_ALIAS_ASSIGNMENT
	                                ;
	TYPE_ALIAS_NAME                 : IDENTIFIER
	                                ;
	TYPE_ALIAS_ASSIGNMENT           : "←" TYPE
	                                ;

	FUNCTION_DECLARATION            : FUNCTION_HEAD FUNCTION_NAME FUNCTION_SIGNATURE
	                                | FUNCTION_HEAD FUNCTION_NAME FUNCTION_SIGNATURE FUNCTION_BODY
	                                | FUNCTION_HEAD FUNCTION_NAME GENERIC_PARAMETER_CLAUSE FUNCTION_SIGNATURE
	                                | FUNCTION_HEAD FUNCTION_NAME GENERIC_PARAMETER_CLAUSE FUNCTION_SIGNATURE FUNCTION_BODY
	                                ;
	FUNCTION_HEAD                   : "subroutine"
	                                ;
	FUNCTION_NAME                   : IDENTIFIER 
	                                | OPERATOR
	                                ;
	FUNCTION_SIGNATURE              : PARAMETER_CLAUSE
	                                | PARAMETER_CLAUSE FUNCTION_RESULT
	                                ;
	FUNCTION_RESULT                 : "→" TYPE
	                                ;
	FUNCTION_BODY                   : CODE_BLOCK
	                                ;
	PARAMETER_CLAUSE                : "(" ")"
	                                | "(" PARAMETER_LIST ")"
	                                ;
	PARAMETER_LIST                  : PARAMETER 
	                                | PARAMETER "," PARAMETER_LIST
	                                ;
	PARAMETER                       : LOCAL_PARAMETER_NAME TYPE_ANNOTATION
	                                | LOCAL_PARAMETER_NAME TYPE_ANNOTATION DEFAULT_ARGUMENT_CLAUSE
	                                | LOCAL_PARAMETER_NAME TYPE_ANNOTATION "…"
	                                ;
	LOCAL_PARAMETER_NAME            : IDENTIFIER
	                                ;
	DEFAULT_ARGUMENT_CLAUSE         : "←" EXPRESSION
	                                ;

	ENUM_DECLARATION                : "ENUM_DECLARATION" ENUM_DECLARATION_NAME "{" "}"
	                                | "ENUM_DECLARATION" ENUM_DECLARATION_NAME "{" ENUM_DECLARATION_MEMBERS "}"
	                                | "ENUM_DECLARATION" ENUM_DECLARATION_NAME GENERIC_WHERE_CLAUSE "{" "}"
	                                | "ENUM_DECLARATION" ENUM_DECLARATION_NAME GENERIC_WHERE_CLAUSE "{" ENUM_DECLARATION_MEMBERS "}"
	                                | "ENUM_DECLARATION" ENUM_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE "{" "}"
	                                | "ENUM_DECLARATION" ENUM_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE "{" ENUM_DECLARATION_MEMBERS "}"
	                                | "ENUM_DECLARATION" ENUM_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE GENERIC_WHERE_CLAUSE "{" "}"
	                                | "ENUM_DECLARATION" ENUM_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE GENERIC_WHERE_CLAUSE "{" ENUM_DECLARATION_MEMBERS "}"
	                                ;
	ENUM_DECLARATION_NAME           : IDENTIFIER
	                                ;
	ENUM_DECLARATION_MEMBERS        : ENUM_DECLARATION_MEMBER
	                                | ENUM_DECLARATION_MEMBER ENUM_DECLARATION_MEMBERS
	                                ;
	ENUM_DECLARATION_MEMBER         : DECLARATION 
	                                | ENUM_DECLARATION_CASE_CLAUSE 
	                                ;
	ENUM_DECLARATION_CASE_CLAUSE    : "case" ENUM_DECLARATION_CASE_LIST
	                                ;
	ENUM_DECLARATION_CASE_LIST      : ENUM_DECLARATION_CASE 
	                                | ENUM_DECLARATION_CASE , ENUM_DECLARATION_CASE_LIST
	                                ;
	ENUM_DECLARATION_CASE           : ENUM_DECLARATION_CASE_NAME
	                                | ENUM_DECLARATION_CASE_NAME ENUM_DECLARATION_ASSIGNMENT
	                                ;
	ENUM_DECLARATION_CASE_NAME      : IDENTIFIER
	                                ;
	ENUM_DECLARATION_ASSIGNMENT     : "←" ENUM_DECLARATION_LITERAL
	                                ;
	ENUM_DECLARATION_LITERAL        : NUMERIC_LITERAL 
	                                | BOOLEAN_LITERAL
	                                ;

	UNION_DECLARATION               : "union" UNION_DECLARATION_NAME "{" "}"
	                                | "union" UNION_DECLARATION_NAME "{" UNION_DECLARATION_MEMBERS "}"
	                                | "union" UNION_DECLARATION_NAME GENERIC_WHERE_CLAUSE "{" "}"
	                                | "union" UNION_DECLARATION_NAME GENERIC_WHERE_CLAUSE "{" UNION_DECLARATION_MEMBERS "}"
	                                | "union" UNION_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE "{" "}"
	                                | "union" UNION_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE "{" UNION_DECLARATION_MEMBERS "}"
	                                | "union" UNION_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE GENERIC_WHERE_CLAUSE "{" "}"
	                                | "union" UNION_DECLARATION_NAME GENERIC_PARAMETER_CLAUSE GENERIC_WHERE_CLAUSE "{" UNION_DECLARATION_MEMBERS "}"
	                                ;
	UNION_DECLARATION_NAME          : IDENTIFIER
	                                ;
	UNION_DECLARATION_MEMBERS       : UNION_DECLARATION_MEMBER
	                                | UNION_DECLARATION_MEMBER UNION_DECLARATION_MEMBERS
	                                ;
	UNION_DECLARATION_MEMBER        : DECLARATION
	                                | UNION_DECLARATION_CASE_CLAUSE
	                                ;
	UNION_DECLARATION_CASE_CLAUSE   : "case" UNION_DECLARATION_CASE_LIST
	                                ;
	UNION_DECLARATION_CASE_LIST     : UNION_DECLARATION_CASE 
	                                | UNION_DECLARATION_CASE "," UNION_DECLARATION_CASE_LIST
	                                ;
	UNION_DECLARATION_CASE          : UNION_DECLARATION_CASE_NAME
	                                | UNION_DECLARATION_CASE_NAME TUPLE_TYPE
	                                ;
	UNION_DECLARATION_CASE_NAME     : IDENTIFIER
	                                ;

	STRUCT_DECLARATION              : "record" STRUCT_NAME GENERIC_PARAMETER_CLAUSE GENERIC_WHERE-CLAUSE STRUCT_BODY
	                                | "record" STRUCT_NAME GENERIC_PARAMETER_CLAUSE STRUCT_BODY
	                                | "record" STRUCT_NAME GENERIC_WHERE-CLAUSE STRUCT_BODY
	                                | "record" STRUCT_NAME STRUCT_BODY
	                                ;                              
	STRUCT_NAME                     : IDENTIFIER
	                                ;
	STRUCT_BODY                     : "{" "}"
	                                | "{" STRUCT_MEMBERS "}"
	                                ;
	STRUCT_MEMBERS                  : STRUCT_MEMBER
	                                | STRUCT_MEMBER STRUCT_MEMBERS
	                                ;
	STRUCT_MEMBER                   : DECLARATION 
	                                ; 

	/*
	 *  PATTERNS
	 */

	PATTERN                           : WILDCARD_PATTERN
	                                  | WILDCARD_PATTERN TYPE_ANNOTATION
	                                  | IDENTIFIER_PATTERN
	                                  | IDENTIFIER_PATTERN TYPE_ANNOTATION
	                                  | VALUE_BINDING_PATTERN
	                                  | TUPLE_PATTERN
	                                  | TUPLE_PATTERN TYPE_ANNOTATION
	                                  | ENUM_DECLARATION_CASE_PATTERN
	                                  | OPTIONAL_PATTERN
	                                  | TYPE_CASTING_PATTERN
	                                  | EXPRESSION_PATTERN
	                                  ;

	WILDCARD_PATTERN                  : "_"
	                                  ;

	IDENTIFIER_PATTERN                : IDENTIFIER
	                                  ;

	TUPLE_PATTERN                     : "⟨" "⟩"
	                                  | "⟨" TUPLE_PATTERN_ELEMENT_LIST "⟩"
	                                  ;
	TUPLE_PATTERN_ELEMENT_LIST        : TUPLE_PATTERN_ELEMENT
	                                  | TUPLE_PATTERN_ELEMENT "," TUPLE_PATTERN_ELEMENT_LIST
	                                  ;
	TUPLE_PATTERN_ELEMENT             : PATTERN 
	                                  | IDENTIFIER ":" PATTERN
	                                  ;

	ENUM_DECLARATION_CASE_PATTERN                 : "." ENUM_DECLARATION_CASE_NAME 
	                                  | "." ENUM_DECLARATION_CASE_NAME TUPLE_PATTERN
	                                  | TYPE_IDENTIFIER "." ENUM_DECLARATION_CASE_NAME
	                                  | TYPE_IDENTIFIER "." ENUM_DECLARATION_CASE_NAME TUPLE_PATTERN
	                                  ;

	OPTIONAL_PATTERN                  : IDENTIFIER_PATTERN "?"
	                                  ;

	TYPE_CASTING_PATTERN              : IS_PATTERN 
	                                  | AS_PATTERN
	                                  ;
	IS_PATTERN                        : "is" TYPE
	                                  ;
	AS_PATTERN                        : PATTERN "as" TYPE
	                                  ;

	EXPRESSION_PATTERN                : EXPRESSION
	                                  ;

	/*
	 *  GENERIC PARAMETERS AND ARGUMENTS
	 */

	GENERIC_PARAMETER_CLAUSE          : "⟨" GENERIC_PARAMETER_LIST "⟩"
	                                  ;
	GENERIC_PARAMETER_LIST            : GENERIC_PARAMETER 
	                                  | GENERIC_PARAMETER "," GENERIC_PARAMETER_LIST
	                                  ;
	GENERIC_PARAMETER                 : TYPE_NAME
	                                  | TYPE_NAME ":" TYPE_IDENTIFIER
	                                  ;
	GENERIC_WHERE_CLAUSE              : "where" REQUIREMENT_LIST
	                                  ;
	REQUIREMENT_LIST                  : REQUIREMENT 
	                                  | REQUIREMENT "," REQUIREMENT_LIST
	                                  ;
	REQUIREMENT                       : CONFORMANCE_REQUIREMENT 
	                                  | SAME_TYPE_REQUIREMENT
	                                  ;
	CONFORMANCE_REQUIREMENT           : TYPE_IDENTIFIER ":" TYPE_IDENTIFIER
	                                  ;
	SAME_TYPE_REQUIREMENT             : TYPE_IDENTIFIER "is" TYPE
	                                  ;

	GENERIC_ARGUMENT_CLAUSE           : "⟨" GENERIC_ARGUMENT_LIST "⟩"
	                                  ;
	GENERIC_ARGUMENT_LIST             : GENERIC_ARGUMENT 
	                                  | GENERIC_ARGUMENT "," GENERIC_ARGUMENT_LIST
	                                  ;
	GENERIC_ARGUMENT                  : TYPE
	                                  ;    


## Influences

[Crystal Programming Language](https://crystal-lang.org/docs/)
[D Programming Language Speci􏰀cation](https://dlang.org/spec/spec.html)
[Go Programming Language Specification, The](https://golang.org/ref/spec)
[Nim Manual](https://nim-lang.org/docs/manual.html)
[Rust Reference, The](https://doc.rust-lang.org/reference/index.html)
[Swift Programming Language, The](https://docs.swift.org/swift-book/)
