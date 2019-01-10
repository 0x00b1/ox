#ifndef OX_OX_HH
#define OX_OX_HH

#include <iostream>
#include <optional>
#include <vector>

#include "type.hh"

namespace Pattern {
    class Pattern {};
}

namespace AST {
    class Visitor;

    class Node;

    class Node {
    public:
        virtual void accept(Visitor &visitor) = 0;
    };

    class Argument;
    class GenericParameter;
    class Parameter;
    class Root;
    class TypeSignature;

    class LabelStatement;

    class ConstantDeclaration;
    class EnumerationDeclaration;
    class ModuleDeclaration;
    class RecordDeclaration;
    class RecordFieldDeclaration;
    class SubroutineDeclaration;
    class TypeAliasDeclaration;
    class UnionDeclaration;

    class ArrayExpression;
    class BinaryOperationExpression;
    class BlockExpression;
    class BooleanLiteralExpression;
    class BreakExpression;
    class CallExpression;
    class ClosureExpression;
    class ConditionalExpression;
    class ContinueExpression;
    class FloatingPointLiteralExpression;
    class ForLoopExpression;
    class IntegerLiteralExpression;
    class RangeExpression;
    class RecordExpression;
    class ReturnExpression;
    class SubscriptExpression;
    class SwitchExpression;
    class TupleExpression;
    class UnaryOperationExpression;
    class WhileLoopExpression;

    class Visitor {
    public:
        virtual void visit(Argument &file) = 0;
        virtual void visit(ArrayExpression &file) = 0;
        virtual void visit(BinaryOperationExpression &file) = 0;
        virtual void visit(BlockExpression &file) = 0;
        virtual void visit(BooleanLiteralExpression &file) = 0;
        virtual void visit(BreakExpression &file) = 0;
        virtual void visit(CallExpression &file) = 0;
        virtual void visit(ClosureExpression &file) = 0;
        virtual void visit(ConstantDeclaration &file) = 0;
        virtual void visit(ContinueExpression &file) = 0;
        virtual void visit(EnumerationDeclaration &file) = 0;
        virtual void visit(FloatingPointLiteralExpression &file) = 0;
        virtual void visit(ForLoopExpression &file) = 0;
        virtual void visit(GenericParameter &file) = 0;
        virtual void visit(ConditionalExpression &file) = 0;
        virtual void visit(IntegerLiteralExpression &file) = 0;
        virtual void visit(LabelStatement &file) = 0;
        virtual void visit(ModuleDeclaration &file) = 0;
        virtual void visit(Parameter &file) = 0;
        virtual void visit(UnaryOperationExpression &file) = 0;
        virtual void visit(RangeExpression &file) = 0;
        virtual void visit(RecordDeclaration &file) = 0;
        virtual void visit(RecordExpression &file) = 0;
        virtual void visit(RecordFieldDeclaration &file) = 0;
        virtual void visit(ReturnExpression &file) = 0;
        virtual void visit(Root &file) = 0;
        virtual void visit(SubroutineDeclaration &file) = 0;
        virtual void visit(SubscriptExpression &file) = 0;
        virtual void visit(SwitchExpression &file) = 0;
        virtual void visit(TupleExpression &file) = 0;
        virtual void visit(TypeAliasDeclaration &file) = 0;
        virtual void visit(TypeSignature &file) = 0;
        virtual void visit(UnionDeclaration &file) = 0;
        virtual void visit(WhileLoopExpression &file) = 0;
    };

    class Root: public Node {
    public:
        Root() {};

        Root(std::vector<AST::Node*> *nodes): nodes(nodes) {};

        std::vector<AST::Node*> *nodes;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class Argument: public Node {
    public:
        Argument(AST::Node *expression): expression(expression) {};

        Argument(std::string name, AST::Node *expression): name(name), expression(expression) {};

        std::string name;

        AST::Node *expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  DECLARATIONS
     */

    class ConstantDeclaration: public Node {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class EnumerationDeclaration: public Node {
    public:
        EnumerationDeclaration(std::string name): name(name) {};

        std::string name;

        Type::Enumerated *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class ModuleDeclaration: public Node {
    public:
        ModuleDeclaration(std::string name): name(name) {};

        ModuleDeclaration(std::string name, std::vector<AST::Node*> members): name(name), members(members) {};

        std::string name;

        std::vector<AST::Node*> members;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class RecordDeclaration: public Node {
    public:
        RecordDeclaration(std::string name, std::vector<AST::RecordFieldDeclaration*> *fields): name(name), fields(fields) {};

        std::string name;

        std::vector<AST::RecordFieldDeclaration*> *fields;

        Type::Record *record;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class RecordFieldDeclaration: public Node {
    public:
        RecordFieldDeclaration(std::string name, Type::Type *type): name(name), type(type) {};

        std::string name;

        Type::Type *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class SubroutineDeclaration: public Node {
    public:
        SubroutineDeclaration(std::string name, AST::TypeSignature *signature): name(name), signature(signature) {};

        std::string name;

        AST::TypeSignature *signature;

        Type::Function *type;

        bool variadic;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class TypeAliasDeclaration: public Node {
    public:
        TypeAliasDeclaration(std::string name, Type::Type *type): name(name), type(type) {};

        std::string name;

        Type::Type *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class UnionDeclaration: public Node {
    public:
        UnionDeclaration(std::string name, std::vector<AST::RecordFieldDeclaration*> *fields): name(name), fields(fields) {};

        std::string name;

        std::vector<AST::RecordFieldDeclaration*> *fields;

        Type::Union *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  EXPRESSIONS
     */

    /*
     *  An array expression, e.g.
     *
     *      [1, 2, 3]
     */
    class ArrayExpression: public Node {
    public:
        ArrayExpression(std::vector<AST::Node*> *items): items(items) {};

        std::vector<AST::Node*> *items;

        Type::Array *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A binary operation expression, e.g.
     *
     *      a + b
     */
    class BinaryOperationExpression: public Node {
    public:
        BinaryOperationExpression(std::string name, AST::Node *a): name(name), a(a) {};

        std::string name;

        AST::Node *a;
        AST::Node *b;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A block expression, e.g.
     *
     *      { true }
     */
    class BlockExpression: public Node {
    public:
        BlockExpression() {};

        BlockExpression(std::vector<AST::Node*> *statements): statements(statements) {};

        std::vector<AST::Node*> *statements;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A Boolean literal expression, e.g.
     *
     *      true
     */
    class BooleanLiteralExpression: public Node {
    public:
        BooleanLiteralExpression(bool value): value(value) {};

        bool value;

        Type::Boolean *type = new Type::Boolean();

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A break expression, e.g.
     *
     *      break
     */
    class BreakExpression: public Node {
    public:
        BreakExpression() {};

        BreakExpression(std::string name): name(name) {};

        BreakExpression(AST::LabelStatement *label): label(label) {};

        std::optional<AST::LabelStatement*> label;

        std::optional<AST::Node*> expression;

        std::string name;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A subroutine call expression, e.g.
     *
     *      f(x)
     */
    class CallExpression: public Node {
    public:
        CallExpression(AST::Node *expression, std::vector<AST::Argument*> *arguments): expression(expression), arguments(arguments) {};

        AST::Node *expression;

        std::vector<AST::Argument*> *arguments;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A closure expression, e.g.
     *
     *      λ (x: 8-bit Integer) → 8-bit Integer { a + 1 }
     */
    class ClosureExpression: public Node {
    public:
        ClosureExpression(AST::BlockExpression *expression): expression(expression) {};

        ClosureExpression(AST::TypeSignature *signature, AST::BlockExpression *expression): signature(signature), expression(expression) {};

        AST::TypeSignature *signature;

        AST::BlockExpression *expression;

        Type::Function *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A conditional expression, e.g.
     *
     *      if true {
     * 
     *      } else {
     *
     *      }
     */
    class ConditionalExpression: public Node {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A continue expression, e.g.
     *
     *      continue
     */
    class ContinueExpression: public Node {
    public:
        ContinueExpression() {};

        ContinueExpression(AST::LabelStatement *label): label(label) {};

        ContinueExpression(std::string name): name(name) {};

        std::optional<AST::LabelStatement*> label;

        std::string name;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A floating-point literal expression, e.g.
     *
     *      1.0
     */
    class FloatingPointLiteralExpression: public Node {
    public:
        FloatingPointLiteralExpression(std::string value): value(value) {};

        std::string value;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A for loop expression, e.g.
     *
     *      for index in 1, 2, … 3 {
     *          
     *      }
     */
    class ForLoopExpression: public Node {
    public:
        ForLoopExpression(Pattern::Pattern *item, AST::Node *container, AST::BlockExpression *expression): item(item), container(container), expression(expression) {};

        Pattern::Pattern *item;

        AST::Node *container;

        AST::BlockExpression *expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  An integer literal expression, e.g.
     *
     *      1
     */
    class IntegerLiteralExpression: public Node {
    public:
        IntegerLiteralExpression(std::string value): value(value) {};

        std::string value;

        Type::Integer *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A range expression, e.g.
     *
     *      1, 2, … 3
     */
    class RangeExpression: public Node {
    public:
        RangeExpression(AST::Node* a, AST::Node* b): a(a), b(b) {};

        RangeExpression(AST::Node* a, AST::Node* b, AST::Node* c): a(a), b(b), c(c) {};

        AST::Node* a;
        AST::Node* b;

        std::optional<AST::Node*> c;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A record expression, e.g.
     *
     *      A { a: 1, b: 2 }
     */
    class RecordExpression: public Node {
    public:
        RecordExpression(std::vector<AST::Node*> *expressions): expressions(expressions) {};

        RecordExpression(std::vector<AST::Node*> *expressions, AST::Node* expression): expressions(expressions), expression(expression) {};

        std::vector<AST::Node*> *expressions;

        std::optional<AST::Node*> expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A return expression, e.g.
     *
     *      return
     */
    class ReturnExpression: public Node {
    public:
        ReturnExpression() {};

        ReturnExpression(AST::Node *expression): expression(expression) {};

        ReturnExpression(AST::LabelStatement *label): label(label) {};

        std::optional<AST::LabelStatement*> label;

        AST::Node *expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A subscript expression, e.g.
     *
     *      a[b]
     */
    class SubscriptExpression: public Node {
    public:
        SubscriptExpression(AST::Node *a, std::vector<AST::Argument*> *b): a(a), b(b) {};

        AST::Node *a;

        std::vector<AST::Argument*> *b;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A switch expression, e.g.
     *
     *      switch a {
     *          case a:
     *          case b:
     *          
     *          default:
     *      }
     */
    class SwitchExpression: public Node {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A tuple expression, e.g.
     *
     *      ⟨1, 2, 3⟩
     */
    class TupleExpression: public Node {
    public:
        TupleExpression(std::vector<AST::Node*> *items): items(items) {};

        std::vector<AST::Node*> *items;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A unary operation expression, e.g.
     *
     *      −a
     */
    class UnaryOperationExpression: public Node {
    public:
        UnaryOperationExpression(AST::Node *a): a(a) {};

        UnaryOperationExpression(std::string operation, AST::Node *a): operation(operation), a(a) {};

        AST::Node *a;

        std::string operation;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    /*
     *  A while loop expression, e.g.
     *
     *      while true {
     *          
     *      }
     */
    class WhileLoopExpression: public Node {
    public:
        WhileLoopExpression(AST::Node *a, AST::BlockExpression *b): a(a), b(b) {};

        AST::Node *a;

        AST::BlockExpression *b;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class GenericParameter: public Node {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class LabelStatement: public Node {
    public:        
        LabelStatement(std::string name): name(name) {};

        LabelStatement(std::string name, AST::Node *statement): name(name), statement(statement) {};

        std::string name;

        AST::Node *statement;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class Parameter: public Node {
    public:
        Parameter(std::string name): name(name) {};

        Parameter(std::string name, AST::Node *expression): name(name), expression(expression) {};

        Parameter(std::string name, Type::Type *type): name(name), type(type) {};

        Parameter(std::string name, Type::Type *type, AST::Node *expression): name(name), type(type), expression(expression) {};

        std::string name;

        Type::Type *type;

        AST::Node *expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class TypeSignature: public Node {
    public:
        TypeSignature() {};

        TypeSignature(std::vector<AST::Parameter*> *parameters): parameters(parameters) {};

        TypeSignature(std::vector<AST::Parameter*> *parameters, Type::Type *type): parameters(parameters), type(type) {};

        std::vector<AST::Parameter*> *parameters;

        Type::Type *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class Generator: public Visitor {
    public:
        void visit(Argument &) override {
            std::cout << "generating Argument" << std::endl;
        }

        void visit(ArrayExpression &) override {
            std::cout << "generating ArrayExpression" << std::endl;
        }

        void visit(UnaryOperationExpression &) override {
            std::cout << "generating UnaryOperationExpression" << std::endl;
        }

        void visit(BlockExpression &) override {
            std::cout << "generating BlockExpression" << std::endl;
        }

        void visit(BooleanLiteralExpression &) override {
            std::cout << "generating BooleanLiteralExpression" << std::endl;
        }

        void visit(BreakExpression &) override {
            std::cout << "generating BreakExpression" << std::endl;
        }

        void visit(CallExpression &) override {
            std::cout << "generating CallExpression" << std::endl;
        }

        void visit(ClosureExpression &) override {
            std::cout << "generating ClosureExpression" << std::endl;
        }

        void visit(ConstantDeclaration &) override {
            std::cout << "generating ConstantDeclaration" << std::endl;
        }

        void visit(ContinueExpression &) override {
            std::cout << "generating ContinueExpression" << std::endl;
        }

        void visit(FloatingPointLiteralExpression &) override {
            std::cout << "generating FloatingPointLiteralExpression" << std::endl;
        }

        void visit(ForLoopExpression &) override {
            std::cout << "generating FloatingPointLiteralExpression" << std::endl;
        }

        void visit(GenericParameter &) override {
            std::cout << "generating GenericParameter" << std::endl;
        }

        void visit(IntegerLiteralExpression &) override {
            std::cout << "generating IntegerLiteralExpression" << std::endl;
        }

        void visit(LabelStatement &) override {
            std::cout << "generating LabelStatement" << std::endl;
        }

        void visit(EnumerationDeclaration &) override {
            std::cout << "generating EnumerationDeclaration" << std::endl;
        }

        void visit(ModuleDeclaration &) override {
            std::cout << "generating ModuleDeclaration" << std::endl;
        }

        void visit(RangeExpression &) override {
            std::cout << "generating RangeExpression" << std::endl;
        }

        void visit(RecordExpression &) override {
            std::cout << "generating RecordExpression" << std::endl;
        }

        void visit(RecordDeclaration &) override {
            std::cout << "generating RecordDeclaration" << std::endl;
        }

        void visit(RecordFieldDeclaration &) override {
            std::cout << "generating RecordFieldDeclaration" << std::endl;
        }

        void visit(ReturnExpression &) override {
            std::cout << "generating ReturnExpression" << std::endl;
        }

        void visit(Root &) override {
            std::cout << "generating Root" << std::endl;
        }

        void visit(SubroutineDeclaration &) override {
            std::cout << "generating SubroutineDeclaration" << std::endl;
        }

        void visit(SwitchExpression &) override {
            std::cout << "generating SwitchExpression" << std::endl;
        }

        void visit(TupleExpression &) override {
            std::cout << "generating TypeAliasDeclaration" << std::endl;
        }

        void visit(TypeAliasDeclaration &) override {
            std::cout << "generating TypeAliasDeclaration" << std::endl;
        }

        void visit(BinaryOperationExpression &) override {
            std::cout << "generating BinaryOperationExpression" << std::endl;
        }

        void visit(UnionDeclaration &) override {
            std::cout << "generating UnionDeclaration" << std::endl;
        }

        void visit(WhileLoopExpression &) override {
            std::cout << "generating WhileLoopExpression" << std::endl;
        }

        void visit(ConditionalExpression &) override {
            std::cout << "generating ConditionalExpression" << std::endl;
        }

        void visit(Parameter &) override {
            std::cout << "generating Parameter" << std::endl;
        }

        void visit(SubscriptExpression &) override {
            std::cout << "generating SubscriptExpression" << std::endl;
        }

        void visit(TypeSignature &) override {
            std::cout << "generating TypeSignature" << std::endl;
        }
    };
}

#endif
