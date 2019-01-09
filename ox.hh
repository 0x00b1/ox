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

    typedef std::vector<AST::Node*> nodes;

    class Node {
    public:
        virtual void accept(Visitor &visitor) = 0;
    };

    class Argument;
    class Label;

    class ConstantDeclaration;
    class EnumerationDeclaration;
    class ModuleDeclaration;
    class SubroutineDeclaration;
    class TypeDeclaration;
    class UnionDeclaration;

    class ArrayExpression;
    class BinaryExpression;
    class BlockExpression;
    class BooleanLiteral;
    class BreakExpression;
    class CallExpression;
    class ClosureExpression;
    class ContinueExpression;
    class FloatingPointLiteral;
    class IndexExpression;
    class IntegerLiteral;
    class PrefixExpression;
    class RangeExpression;
    class RecordExpression;
    class SubscriptExpression;
    class TupleExpression;
    
    class ForLoop;
    class GenericParameter;
    class Goto;
    class IfStatement;
    class OperatorDeclaration;
    class Parameter;
    class RecordDeclaration;
    class RecordField;
    class ReturnStatement;
    class Root;
    class SwitchStatement;
    class TypeSignature;
    class WhileLoop;

    class Visitor {
    public:
        virtual void visit(Argument &file) = 0;
        virtual void visit(ArrayExpression &file) = 0;
        virtual void visit(BinaryExpression &file) = 0;
        virtual void visit(BlockExpression &file) = 0;
        virtual void visit(BooleanLiteral &file) = 0;
        virtual void visit(BreakExpression &file) = 0;
        virtual void visit(CallExpression &file) = 0;
        virtual void visit(ClosureExpression &file) = 0;
        virtual void visit(ConstantDeclaration &file) = 0;
        virtual void visit(ContinueExpression &file) = 0;
        virtual void visit(EnumerationDeclaration &file) = 0;
        virtual void visit(FloatingPointLiteral &file) = 0;
        virtual void visit(ForLoop &file) = 0;
        virtual void visit(GenericParameter &file) = 0;
        virtual void visit(Goto &file) = 0;
        virtual void visit(IfStatement &file) = 0;
        virtual void visit(IndexExpression &file) = 0;
        virtual void visit(IntegerLiteral &file) = 0;
        virtual void visit(Label &file) = 0;
        virtual void visit(ModuleDeclaration &file) = 0;
        virtual void visit(OperatorDeclaration &file) = 0;
        virtual void visit(Parameter &file) = 0;
        virtual void visit(PrefixExpression &file) = 0;
        virtual void visit(RangeExpression &file) = 0;
        virtual void visit(RecordDeclaration &file) = 0;
        virtual void visit(RecordExpression &file) = 0;
        virtual void visit(RecordField &file) = 0;
        virtual void visit(ReturnStatement &file) = 0;
        virtual void visit(Root &file) = 0;
        virtual void visit(SubroutineDeclaration &file) = 0;
        virtual void visit(SubscriptExpression &file) = 0;
        virtual void visit(SwitchStatement &file) = 0;
        virtual void visit(TupleExpression &file) = 0;
        virtual void visit(TypeDeclaration &file) = 0;
        virtual void visit(TypeSignature &file) = 0;
        virtual void visit(UnionDeclaration &file) = 0;
        virtual void visit(WhileLoop &file) = 0;
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

    class ArrayExpression: public Node {
    public:
        ArrayExpression(std::vector<AST::Node*> *items): items(items) {};

        std::vector<AST::Node*> *items;

        Type::Array *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class BinaryExpression: public Node {
    public:
        BinaryExpression(std::string operation, AST::Node *a): operation(operation), a(a) {};

        std::string operation;

        AST::Node *a;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class BlockExpression: public Node {
    public:
        BlockExpression() {};

        BlockExpression(std::vector<AST::Node*> *statements): statements(statements) {};

        std::vector<AST::Node*> *statements;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class BooleanLiteral: public Node {
    public:
        BooleanLiteral(bool value): value(value) {};

        bool value;

        Type::Boolean *type = new Type::Boolean();

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class BreakExpression: public Node {
    public:
        BreakExpression() {};

        BreakExpression(std::string name): name(name) {};

        BreakExpression(AST::Label *label): label(label) {};

        std::optional<AST::Label*> label;

        std::string name;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class CallExpression: public Node {
    public:
        CallExpression(AST::Node *expression, std::vector<AST::Argument*> *arguments): expression(expression), arguments(arguments) {};

        AST::Node *expression;

        std::vector<AST::Argument*> *arguments;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

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

    class ConstantDeclaration: public Node {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class ContinueExpression: public Node {
    public:
        ContinueExpression() {};

        ContinueExpression(AST::Label *label): label(label) {};

        ContinueExpression(std::string name): name(name) {};

        std::optional<AST::Label*> label;

        std::string name;

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

    class FloatingPointLiteral: public Node {
    public:
        FloatingPointLiteral(std::string value): value(value) {};

        std::string value;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class ForLoop: public Node {
    public:
        ForLoop(Pattern::Pattern *item, AST::Node *container, AST::BlockExpression *expression): item(item), container(container), expression(expression) {};

        Pattern::Pattern *item;

        AST::Node *container;

        AST::BlockExpression *expression;

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

    class Goto: public Node {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class IfStatement: public Node {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class IndexExpression: public Node {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class IntegerLiteral: public Node {
    public:
        IntegerLiteral(std::string value): value(value) {};

        std::string value;

        Type::Integer *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class Label: public Node {
    public:        
        Label(std::string name): name(name) {};

        Label(std::string name, AST::Node *statement): name(name), statement(statement) {};

        std::string name;

        AST::Node *statement;

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

    class OperatorDeclaration: public Node {
    public:
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

    class PrefixExpression: public Node {
    public:
        PrefixExpression(AST::Node *a): a(a) {};

        PrefixExpression(std::string operation, AST::Node *a): operation(operation), a(a) {};

        AST::Node *a;

        std::string operation;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class RangeExpression: public Node {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class RecordExpression: public Node {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class RecordDeclaration: public Node {
    public:
        RecordDeclaration(std::string name, std::vector<AST::RecordField*> *fields): name(name), fields(fields) {};

        std::string name;

        std::vector<AST::RecordField*> *fields;

        Type::Record *record;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class RecordField: public Node {
    public:
        RecordField(std::string name, Type::Type *type): name(name), type(type) {};

        std::string name;

        Type::Type *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class ReturnStatement: public Node {
    public:
        ReturnStatement() {};

        ReturnStatement(AST::Node *expression): expression(expression) {};

        ReturnStatement(AST::Label *label): label(label) {};

        std::optional<AST::Label*> label;

        AST::Node *expression;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
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

    class SubroutineDeclaration: public Node {
    public:
        SubroutineDeclaration(std::string name, AST::TypeSignature *signature): name(name), signature(signature) {};

        std::string name;

        AST::TypeSignature *signature;

        Type::Function *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class SubscriptExpression: public Node {
    public:
        SubscriptExpression(AST::Node *expression, std::vector<AST::Argument*> *arguments): expression(expression), arguments(arguments) {};

        AST::Node *expression;

        std::vector<AST::Argument*> *arguments;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class SwitchStatement: public Node {
    public:
        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class TupleExpression: public Node {
    public:
        TupleExpression(std::vector<AST::Node*> *items): items(items) {};

        std::vector<AST::Node*> *items;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class TypeDeclaration: public Node {
    public:
        TypeDeclaration(std::string name, Type::Type *type): name(name), type(type) {};

        std::string name;

        Type::Type *type;

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

    class UnionDeclaration: public Node {
    public:
        UnionDeclaration(std::string name, std::vector<AST::RecordField*> *fields): name(name), fields(fields) {};

        std::string name;

        std::vector<AST::RecordField*> *fields;

        Type::Union *type;

        void accept(Visitor &visitor) override {
            visitor.visit(*this);
        }
    };

    class WhileLoop: public Node {
    public:
        WhileLoop(AST::Node *condition, AST::BlockExpression *expression): condition(condition), expression(expression) {};

        AST::Node *condition;

        AST::BlockExpression *expression;

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

        void visit(PrefixExpression &) override {
            std::cout << "generating PrefixExpression" << std::endl;
        }

        void visit(BlockExpression &) override {
            std::cout << "generating BlockExpression" << std::endl;
        }

        void visit(BooleanLiteral &) override {
            std::cout << "generating BooleanLiteral" << std::endl;
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

        void visit(FloatingPointLiteral &) override {
            std::cout << "generating FloatingPointLiteral" << std::endl;
        }

        void visit(ForLoop &) override {
            std::cout << "generating FloatingPointLiteral" << std::endl;
        }

        void visit(GenericParameter &) override {
            std::cout << "generating Goto" << std::endl;
        }

        void visit(Goto &) override {
            std::cout << "generating Goto" << std::endl;
        }

        void visit(IndexExpression &) override {
            std::cout << "generating IndexExpression" << std::endl;
        }

        void visit(IntegerLiteral &) override {
            std::cout << "generating IntegerLiteral" << std::endl;
        }

        void visit(Label &) override {
            std::cout << "generating Label" << std::endl;
        }

        void visit(EnumerationDeclaration &) override {
            std::cout << "generating EnumerationDeclaration" << std::endl;
        }

        void visit(ModuleDeclaration &) override {
            std::cout << "generating ModuleDeclaration" << std::endl;
        }

        void visit(OperatorDeclaration &) override {
            std::cout << "generating OperatorDeclaration" << std::endl;
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

        void visit(RecordField &) override {
            std::cout << "generating RecordField" << std::endl;
        }

        void visit(ReturnStatement &) override {
            std::cout << "generating ReturnStatement" << std::endl;
        }

        void visit(Root &) override {
            std::cout << "generating Root" << std::endl;
        }

        void visit(SubroutineDeclaration &) override {
            std::cout << "generating SubroutineDeclaration" << std::endl;
        }

        void visit(SwitchStatement &) override {
            std::cout << "generating SwitchStatement" << std::endl;
        }

        void visit(TupleExpression &) override {
            std::cout << "generating TypeDeclaration" << std::endl;
        }

        void visit(TypeDeclaration &) override {
            std::cout << "generating TypeDeclaration" << std::endl;
        }

        void visit(BinaryExpression &) override {
            std::cout << "generating BinaryExpression" << std::endl;
        }

        void visit(UnionDeclaration &) override {
            std::cout << "generating UnionDeclaration" << std::endl;
        }

        void visit(WhileLoop &) override {
            std::cout << "generating WhileLoop" << std::endl;
        }

        void visit(IfStatement &) override {
            std::cout << "generating IfStatement" << std::endl;
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
