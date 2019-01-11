#ifndef OX_GENERATOR_HH
#define OX_GENERATOR_HH

#include <iostream>

#include "ast.hh"

class Generator: public Visitor {
public:
    Generator() {};

    virtual ~Generator() {};

    void visit(AST::Node &) override {
        std::cout << "generating Node" << std::endl;
    }

    void visit(AST::Root &root) override {
        std::cout << "generating Root" << std::endl;
    }

    void visit(AST::Argument &) override {
        std::cout << "generating Argument" << std::endl;
    }

    void visit(AST::ArrayExpression &) override {
        std::cout << "generating ArrayExpression" << std::endl;
    }

    void visit(AST::UnaryOperationExpression &) override {
        std::cout << "generating UnaryOperationExpression" << std::endl;
    }

    void visit(AST::BlockExpression &) override {
        std::cout << "generating BlockExpression" << std::endl;
    }

    void visit(AST::BooleanLiteralExpression &) override {
        std::cout << "generating BooleanLiteralExpression" << std::endl;
    }

    void visit(AST::BreakExpression &) override {
        std::cout << "generating BreakExpression" << std::endl;
    }

    void visit(AST::CallExpression &) override {
        std::cout << "generating CallExpression" << std::endl;
    }

    void visit(AST::ClosureExpression &) override {
        std::cout << "generating ClosureExpression" << std::endl;
    }

    void visit(AST::ConstantDeclaration &) override {
        std::cout << "generating ConstantDeclaration" << std::endl;
    }

    void visit(AST::ContinueExpression &) override {
        std::cout << "generating ContinueExpression" << std::endl;
    }

    void visit(AST::FloatingPointLiteralExpression &) override {
        std::cout << "generating FloatingPointLiteralExpression" << std::endl;
    }

    void visit(AST::ForLoopExpression &) override {
        std::cout << "generating FloatingPointLiteralExpression" << std::endl;
    }

    void visit(AST::GenericParameter &) override {
        std::cout << "generating GenericParameter" << std::endl;
    }

    void visit(AST::IntegerLiteralExpression &) override {
        std::cout << "generating IntegerLiteralExpression" << std::endl;
    }

    void visit(AST::LabelDeclaration &) override {
        std::cout << "generating LabelDeclaration" << std::endl;
    }

    void visit(AST::EnumerationDeclaration &) override {
        std::cout << "generating EnumerationDeclaration" << std::endl;
    }

    void visit(AST::ModuleDeclaration &) override {
        std::cout << "generating ModuleDeclaration" << std::endl;
    }

    void visit(AST::RangeExpression &) override {
        std::cout << "generating RangeExpression" << std::endl;
    }

    void visit(AST::RecordExpression &) override {
        std::cout << "generating RecordExpression" << std::endl;
    }

    void visit(AST::RecordDeclaration &) override {
        std::cout << "generating RecordDeclaration" << std::endl;
    }

    void visit(AST::RecordFieldDeclaration &) override {
        std::cout << "generating RecordFieldDeclaration" << std::endl;
    }

    void visit(AST::ReturnExpression &) override {
        std::cout << "generating ReturnExpression" << std::endl;
    }

    void visit(AST::SubroutineDeclaration &) override {
        std::cout << "generating SubroutineDeclaration" << std::endl;
    }

    void visit(AST::SwitchExpression &) override {
        std::cout << "generating SwitchExpression" << std::endl;
    }

    void visit(AST::TupleExpression &) override {
        std::cout << "generating TypeAliasDeclaration" << std::endl;
    }

    void visit(AST::TypeAliasDeclaration &) override {
        std::cout << "generating TypeAliasDeclaration" << std::endl;
    }

    void visit(AST::BinaryOperationExpression &) override {
        std::cout << "generating BinaryOperationExpression" << std::endl;
    }

    void visit(AST::UnionDeclaration &) override {
        std::cout << "generating UnionDeclaration" << std::endl;
    }

    void visit(AST::WhileLoopExpression &) override {
        std::cout << "generating WhileLoopExpression" << std::endl;
    }

    void visit(AST::ConditionalExpression &) override {
        std::cout << "generating ConditionalExpression" << std::endl;
    }

    void visit(AST::Parameter &) override {
        std::cout << "generating Parameter" << std::endl;
    }

    void visit(AST::SubscriptExpression &) override {
        std::cout << "generating SubscriptExpression" << std::endl;
    }

    void visit(AST::TypeSignature &) override {
        std::cout << "generating TypeSignature" << std::endl;
    }
};
    
#endif
