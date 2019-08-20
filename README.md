# Ox

## Examples

```
subroutine fibonacci(maximum: Integer):
    a: Integer ← 0
    b: Integer ← 1

    while a < maximum:
        a ← b
        b ← a + b

fibonacci(1000)
```

## Grammar

### EBNF

```ebnf
Unit                     = { Statement } 
                         ;
Statement                = DECLARATION_STATEMENT ";"
                         | Expression ";"
                         | "return" [ Expression ] ";"
                         ;
DECLARATION_STATEMENT    = SubroutineDeclaration
                         | VariableDeclaration
                         ;
SubroutineDeclaration    = "subroutine" Identifier FunctionType [ BlockExpression ]
                         ;
VariableDeclaration      = [ "constant" ] Identifier [ ":" Type ] "←" Expression
                         ;
Expression               = "(" Expression ")"
                         | ArrayExpression
                         | BlockExpression
                         | CallExpression
                         | ConditionalExpression
                         | IndexExpression
                         | LiteralExpression
                         | PathExpression
                         ;
BlockExpression          = "{" Statement { Statement } "}" 
                         ;
ConditionalExpression    = "if" Expression BlockExpression ( "else" ( BlockExpression | ConditionalExpression ) ) 
                         ;
ArrayExpression          = "[" Expression { "," Expression } "]"
                         ;
CallExpression           = Expression "(" Expression { "," Expression } ")"
                         ;
IndexExpression          = Expression "[" Expression "]"
                         ;
LiteralExpression        = BooleanExpression
                         | FloatingPointExpression
                         | IntegerExpression
                         ;
BooleanExpression        = BooleanLiteral
                         ;
FloatingPointExpression  = FloatingPointLiteral
                         ;
IntegerExpression        = IntegerLiteral
                         ;
PathExpression           = Identifier
                         ;
Type                     = ArrayType
                         | BooleanType
                         | FloatingPointType
                         | FunctionType
                         | IntegerType
                         | ReferenceType
                         | SliceType
                         ;
ArrayType                = "[" Type { "×" Expression } "]" 
                         ;
BooleanType              = "Boolean" 
                         ;
FloatingPointType        = ( "32-bit" | "64-bit" ) "Floating-point" 
                         ;
FunctionType             = "(" [ [ Identifier ":" ] Type { "," [ Identifier ":" ] Type } ] ")" "→" Type 
                         ;
IntegerType              = [ "unsigned" ] ( ( ( "8-bit" | "16-bit" | "32-bit" | "64-bit" ) "Integer" ) | "Size" ) ) 
                         ;
ReferenceType            = [ "shared" ] "reference" Type 
                         ;
SliceType                = "[" Type "]" 
                         ;
```

### LALR(1)

```yacc
UNIT                        : STATEMENTS
                            ;
STATEMENTS                  : STATEMENT
                            | STATEMENTS STATEMENT
                            ;
STATEMENT                   : BLOCK_STATEMENT
                            | DECLARATION_STATEMENT
                            | EXPRESSION_STATEMENT
                            | RETURN_STATEMENT
                            ;
BLOCK_STATEMENT             : "{" STATEMENTS "}" 
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
                            | BLOCK_STATEMENT
                            | CALL_EXPRESSION
                            | CONDITIONAL_EXPRESSION
                            | INDEX_EXPRESSION
                            | LITERAL_EXPRESSION
                            | PATH_EXPRESSION
                            ;
CONDITIONAL_EXPRESSION      : "if" EXPRESSION BLOCK_STATEMENT
                            | "if" EXPRESSION BLOCK_STATEMENT "else" BLOCK_STATEMENT
                            ;
ARRAY_EXPRESSION            : "[" ELEMENTS "]"
                            ;
ELEMENTS                    : EXPRESSION
                            | ELEMENTS "," EXPRESSION
                            ;
CALL_EXPRESSION             : EXPRESSION "(" ARGUMENTS ")"
                            ;
ARGUMENTS                   : EXPRESSION
                            | ARGUMENTS "," EXPRESSION
                            ;                          
INDEX_EXPRESSION            : EXPRESSION "[" EXPRESSION "]"
                            ;
LITERAL_EXPRESSION          : BOOLEAN_EXPRESSION
                            | FLOATING_POINT_EXPRESSION
                            | INTEGER_EXPRESSION
                            ;
BOOLEAN_EXPRESSION          : BOOLEAN_LITERAL
                            ;
FLOATING_POINT_EXPRESSION   : FLOATING_POINT_LITERAL
                            ;
INTEGER_EXPRESSION          : INTEGER_LITERAL
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
```

## Abstract Syntax Tree (Node)

```c++
Node::Parameter
    identifier: Node::Identifier
    pattern: std::shared_ptr<Node::Pattern>
    type: std::shared_ptr<Node::Type>

Node::Block
    postfix_expression: std::option<std::shared_ptr<Node::Expression>>
    identifier: Node::Identifier
    statements: std::vector<std::shared_ptr<Node::Statement>>

Node::Expression
    identifier: Node::Identifier
    node: std::shared_ptr<Node::ExpressionVariant>

Node::Identifier
    name: std::string

Node::Item
    identifier: Node::Identifier
    node: std::shared_ptr<Node::ItemVariant>

Node::Literal
    node: std::shared_ptr<Node::LiteralVariant>
    token: std::string

Node::Name
    identifier: std::string

Node::Pattern
    identifier: Node::Identifier
    node: std::shared_ptr<Node::PatternVariant>

Node::Statement
    identifier: Node::Identifier
    node: std::shared_ptr<Node::StatementVariant>

Node::Type
    identifier: Node::Identifier
    node: std::shared_ptr<Node::TypeVariant>

Node::ArrayExpression
Node::CallExpression
Node::IndexExpression
Node::LiteralExpression

Node::ConstantItem
Node::SubroutineItem

Node::BooleanLiteral
Node::FloatingPointLiteral
Node::IntegerLiteral

Node::ConditionalStatement
Node::ReturnStatement
```
