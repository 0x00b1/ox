#ifndef OX_GENERATOR_HH
#define OX_GENERATOR_HH

#include <iostream>
#include <memory>

#include "visitor.hh"

class Generator: public Visitor {
public:
    void accept(std::shared_ptr<AST::AnonymousConstant> node) override {}
    void accept(std::shared_ptr<AST::Argument> node) override {}
    void accept(std::shared_ptr<AST::Block> node) override {}
    void accept(std::shared_ptr<AST::Declaration> node) override {}
    void accept(std::shared_ptr<AST::Expression> node) override {}
    void accept(std::shared_ptr<AST::Field> node) override {}
    void accept(std::shared_ptr<AST::FunctionPrototype> node) override {}
    void accept(std::shared_ptr<AST::GenericParameter> node) override {}
    void accept(std::shared_ptr<AST::Identifier> node) override {}
    void accept(std::shared_ptr<AST::Label> node) override {}
    void accept(std::shared_ptr<AST::Path> node) override {}
    void accept(std::shared_ptr<AST::Pattern> node) override {}
    void accept(std::shared_ptr<AST::RecordField> node) override {}
    void accept(std::shared_ptr<AST::Statement> node) override {}
    void accept(std::shared_ptr<AST::Type> node) override {}
    void accept(std::shared_ptr<AST::Variant> node) override {}
    void accept(std::shared_ptr<Declaration::Constant> node) override {}
    void accept(std::shared_ptr<Declaration::Enumeration> node) override {}
    void accept(std::shared_ptr<Declaration::Module> node) override {}
    void accept(std::shared_ptr<Declaration::Record> node) override {}
    void accept(std::shared_ptr<Declaration::Subroutine> node) override {}
    void accept(std::shared_ptr<Declaration::TaggedUnion> node) override {}
    void accept(std::shared_ptr<Declaration::TypeAlias> node) override {}

    void accept(std::shared_ptr<Expression::Array> node) override {
        for (const auto &element: node->elements) {
            element->accept(*this);
        }
    }

    void accept(std::shared_ptr<Expression::Assignment> node) override {}
    void accept(std::shared_ptr<Expression::BinaryOperation> node) override {}
    void accept(std::shared_ptr<Expression::Block> node) override {}
    void accept(std::shared_ptr<Expression::BooleanLiteral> node) override {}
    void accept(std::shared_ptr<Expression::Break> node) override {}
    void accept(std::shared_ptr<Expression::Call> node) override {}
    void accept(std::shared_ptr<Expression::Closure> node) override {}
    void accept(std::shared_ptr<Expression::Conditional> node) override {}
    void accept(std::shared_ptr<Expression::Continue> node) override {}
    void accept(std::shared_ptr<Expression::FloatingPointLiteral> node) override {}
    void accept(std::shared_ptr<Expression::ForLoop> node) override {}
    void accept(std::shared_ptr<Expression::Index> node) override {}
    void accept(std::shared_ptr<Expression::IntegerLiteral> node) override {}
    void accept(std::shared_ptr<Expression::Member> node) override {}
    void accept(std::shared_ptr<Expression::Range> node) override {}
    void accept(std::shared_ptr<Expression::Record> node) override {}
    void accept(std::shared_ptr<Expression::Reference> node) override {}
    void accept(std::shared_ptr<Expression::Return> node) override {}
    void accept(std::shared_ptr<Expression::Switch> node) override {}
    void accept(std::shared_ptr<Expression::Tuple> node) override {}
    void accept(std::shared_ptr<Expression::UnaryOperation> node) override {}
    void accept(std::shared_ptr<Expression::WhileLoop> node) override {}
    void accept(std::shared_ptr<Statement::Declaration> node) override {}
    void accept(std::shared_ptr<Statement::Expression> node) override {}
    void accept(std::shared_ptr<Type::Boolean> node) override {}
    void accept(std::shared_ptr<Type::FloatingPoint> node) override {}
    void accept(std::shared_ptr<Type::Integer> node) override {}
    void accept(std::shared_ptr<Variant::Record> node) override {}
    void accept(std::shared_ptr<Variant::Tuple> node) override {}
    void accept(std::shared_ptr<Variant::Unit> node) override {}
};

#endif
