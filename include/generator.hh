#ifndef OX_GENERATOR_HH
#define OX_GENERATOR_HH

#include <iostream>

#include "ast.hh"

class Generator: public Visitor {
public:
    Generator() = default;

    ~Generator() override = default;

    void visit(const AST::Argument &node) override;
    void visit(const AST::ArrayExpression &node) override;
    void visit(const AST::BinaryOperationExpression &node) override;
    void visit(const AST::BlockExpression &node) override;
    void visit(const AST::BooleanLiteralExpression &node) override;
    void visit(const AST::BreakExpression &node) override;
    void visit(const AST::CallExpression &node) override;
    void visit(const AST::ClosureExpression &node) override;
    void visit(const AST::ConditionalExpression &node) override;
    void visit(const AST::ConstantDeclaration &node) override;
    void visit(const AST::ContinueExpression &node) override;
    void visit(const AST::Declaration &node) override;
    void visit(const AST::EnumerationDeclaration &node) override;
    void visit(const AST::Expression &node) override;
    void visit(const AST::FloatingPointLiteralExpression &node) override;
    void visit(const AST::ForLoopExpression &node) override;
    void visit(const AST::GenericParameter &node) override;
    void visit(const AST::IntegerLiteralExpression &node) override;
    void visit(const AST::LabelDeclaration &node) override;
    void visit(const AST::ModuleDeclaration &node) override;
    void visit(const AST::Node &node) override;
    void visit(const AST::Parameter &node) override;
    void visit(const AST::RangeExpression &node) override;
    void visit(const AST::RecordDeclaration &node) override;
    void visit(const AST::RecordExpression &node) override;
    void visit(const AST::RecordFieldDeclaration &node) override;
    void visit(const AST::ReturnExpression &node) override;
    void visit(const AST::Root &root) override;
    void visit(const AST::Statement &node) override;
    void visit(const AST::SubroutineDeclaration &node) override;
    void visit(const AST::SubscriptExpression &node) override;
    void visit(const AST::SwitchExpression &node) override;
    void visit(const AST::TupleExpression &node) override;
    void visit(const AST::TypeAliasDeclaration &node) override;
    void visit(const AST::TypeSignature &node) override;
    void visit(const AST::UnaryOperationExpression &node) override;
    void visit(const AST::UnionDeclaration &node) override;
    void visit(const AST::WhileLoopExpression &node) override;
};

#endif
