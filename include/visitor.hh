#ifndef OX_VISITOR_HH
#define OX_VISITOR_HH

#include <memory>

class Visitor;

namespace AST {
    class Node {
    public:
        virtual void accept(Visitor &visitor) = 0;
    };
}

namespace AST {
    class AnonymousConstant;
    class Argument;
    class Block;
    class Declaration;
    class Expression;
    class Field;
    class FunctionPrototype;
    class GenericParameter;
    class Identifier;
    class Label;
    class Path;
    class Pattern;
    class RecordField;
    class Statement;
    class Type;
    class Variant;
}

namespace Declaration {
    class Constant;
    class Enumeration;
    class Module;
    class Record;
    class Subroutine;
    class TaggedUnion;
    class TypeAlias;
}

namespace Expression {
    class Array;
    class Assignment;
    class BinaryOperation;
    class Block;
    class BooleanLiteral;
    class Break;
    class Call;
    class Closure;
    class Conditional;
    class Continue;
    class FloatingPointLiteral;
    class ForLoop;
    class Index;
    class IntegerLiteral;
    class Member;
    class Range;
    class Record;
    class Reference;
    class Return;
    class Switch;
    class Tuple;
    class UnaryOperation;
    class WhileLoop;
}

namespace Statement {
    class Declaration;
    class Expression;
}

namespace Type {
    class Boolean;
    class Integer;
    class FloatingPoint;
}

namespace Variant {
    class Record;
    class Tuple;
    class Unit;
}

class Visitor {
public:
    virtual void accept(std::shared_ptr<AST::AnonymousConstant>) = 0;
    virtual void accept(std::shared_ptr<AST::Argument>) = 0;
    virtual void accept(std::shared_ptr<AST::Block>) = 0;
    virtual void accept(std::shared_ptr<AST::Declaration>) = 0;
    virtual void accept(std::shared_ptr<AST::Expression>) = 0;
    virtual void accept(std::shared_ptr<AST::Field>) = 0;
    virtual void accept(std::shared_ptr<AST::FunctionPrototype>) = 0;
    virtual void accept(std::shared_ptr<AST::GenericParameter>) = 0;
    virtual void accept(std::shared_ptr<AST::Identifier>) = 0;
    virtual void accept(std::shared_ptr<AST::Label>) = 0;
    virtual void accept(std::shared_ptr<AST::Path>) = 0;
    virtual void accept(std::shared_ptr<AST::Pattern>) = 0;
    virtual void accept(std::shared_ptr<AST::RecordField>) = 0;
    virtual void accept(std::shared_ptr<AST::Statement>) = 0;
    virtual void accept(std::shared_ptr<AST::Type>) = 0;
    virtual void accept(std::shared_ptr<AST::Variant>) = 0;
    virtual void accept(std::shared_ptr<Declaration::Constant>) = 0;
    virtual void accept(std::shared_ptr<Declaration::Enumeration>) = 0;
    virtual void accept(std::shared_ptr<Declaration::Module>) = 0;
    virtual void accept(std::shared_ptr<Declaration::Record>) = 0;
    virtual void accept(std::shared_ptr<Declaration::Subroutine>) = 0;
    virtual void accept(std::shared_ptr<Declaration::TaggedUnion>) = 0;
    virtual void accept(std::shared_ptr<Declaration::TypeAlias>) = 0;
    virtual void accept(std::shared_ptr<Expression::Array>) = 0;
    virtual void accept(std::shared_ptr<Expression::Assignment>) = 0;
    virtual void accept(std::shared_ptr<Expression::BinaryOperation>) = 0;
    virtual void accept(std::shared_ptr<Expression::Block>) = 0;
    virtual void accept(std::shared_ptr<Expression::BooleanLiteral>) = 0;
    virtual void accept(std::shared_ptr<Expression::Break>) = 0;
    virtual void accept(std::shared_ptr<Expression::Call>) = 0;
    virtual void accept(std::shared_ptr<Expression::Closure>) = 0;
    virtual void accept(std::shared_ptr<Expression::Conditional>) = 0;
    virtual void accept(std::shared_ptr<Expression::Continue>) = 0;
    virtual void accept(std::shared_ptr<Expression::FloatingPointLiteral>) = 0;
    virtual void accept(std::shared_ptr<Expression::ForLoop>) = 0;
    virtual void accept(std::shared_ptr<Expression::Index>) = 0;
    virtual void accept(std::shared_ptr<Expression::IntegerLiteral>) = 0;
    virtual void accept(std::shared_ptr<Expression::Member>) = 0;
    virtual void accept(std::shared_ptr<Expression::Range>) = 0;
    virtual void accept(std::shared_ptr<Expression::Record>) = 0;
    virtual void accept(std::shared_ptr<Expression::Reference>) = 0;
    virtual void accept(std::shared_ptr<Expression::Return>) = 0;
    virtual void accept(std::shared_ptr<Expression::Switch>) = 0;
    virtual void accept(std::shared_ptr<Expression::Tuple>) = 0;
    virtual void accept(std::shared_ptr<Expression::UnaryOperation>) = 0;
    virtual void accept(std::shared_ptr<Expression::WhileLoop>) = 0;
    virtual void accept(std::shared_ptr<Statement::Declaration>) = 0;
    virtual void accept(std::shared_ptr<Statement::Expression>) = 0;
    virtual void accept(std::shared_ptr<Type::Boolean>) = 0;
    virtual void accept(std::shared_ptr<Type::FloatingPoint>) = 0;
    virtual void accept(std::shared_ptr<Type::Integer>) = 0;
    virtual void accept(std::shared_ptr<Variant::Record>) = 0;
    virtual void accept(std::shared_ptr<Variant::Tuple>) = 0;
    virtual void accept(std::shared_ptr<Variant::Unit>) = 0;
};

#endif
