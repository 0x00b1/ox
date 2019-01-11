#ifndef OX_VISITOR_HH
#define OX_VISITOR_HH

#include "node.hh"

namespace AST {
    class Argument;
    class ArrayExpression;
    class BinaryOperationExpression;
    class BlockExpression;
    class BooleanLiteralExpression;
    class BreakExpression;
    class CallExpression;
    class ClosureExpression;
    class ConditionalExpression;
    class ConstantDeclaration;
    class ContinueExpression;
    class EnumerationDeclaration;
    class FloatingPointLiteralExpression;
    class ForLoopExpression;
    class GenericParameter;
    class IntegerLiteralExpression;
    class LabelDeclaration;
    class ModuleDeclaration;
    class Parameter;
    class RangeExpression;
    class RecordDeclaration;
    class RecordExpression;
    class RecordFieldDeclaration;
    class ReturnExpression;
    class Root;
    class SubroutineDeclaration;
    class SubscriptExpression;
    class SwitchExpression;
    class TupleExpression;
    class TypeAliasDeclaration;
    class TypeSignature;
    class UnaryOperationExpression;
    class UnionDeclaration;
    class WhileLoopExpression;
}

class Visitor {
public:
    virtual void visit(const AST::Argument &node);
    virtual void visit(const AST::ArrayExpression &node);
    virtual void visit(const AST::BinaryOperationExpression &node);
    virtual void visit(const AST::BlockExpression &node);
    virtual void visit(const AST::BooleanLiteralExpression &node);
    virtual void visit(const AST::BreakExpression &node);
    virtual void visit(const AST::CallExpression &node);
    virtual void visit(const AST::ClosureExpression &node);
    virtual void visit(const AST::ConditionalExpression &node);
    virtual void visit(const AST::ConstantDeclaration &node);
    virtual void visit(const AST::ContinueExpression &node);
    virtual void visit(const AST::EnumerationDeclaration &node);
    virtual void visit(const AST::FloatingPointLiteralExpression &node);
    virtual void visit(const AST::ForLoopExpression &node);
    virtual void visit(const AST::GenericParameter &node);
    virtual void visit(const AST::IntegerLiteralExpression &node);
    virtual void visit(const AST::LabelDeclaration &node);
    virtual void visit(const AST::ModuleDeclaration &node);
    virtual void visit(const AST::Node &node);
    virtual void visit(const AST::Parameter &node);
    virtual void visit(const AST::RangeExpression &node);
    virtual void visit(const AST::RecordDeclaration &node);
    virtual void visit(const AST::RecordExpression &node);
    virtual void visit(const AST::RecordFieldDeclaration &node);
    virtual void visit(const AST::ReturnExpression &node);
    virtual void visit(const AST::Root &node);
    virtual void visit(const AST::SubroutineDeclaration &node);
    virtual void visit(const AST::SubscriptExpression &node);
    virtual void visit(const AST::SwitchExpression &node);
    virtual void visit(const AST::TupleExpression &node);
    virtual void visit(const AST::TypeAliasDeclaration &node);
    virtual void visit(const AST::TypeSignature &node);
    virtual void visit(const AST::UnaryOperationExpression &node);
    virtual void visit(const AST::UnionDeclaration &node);
    virtual void visit(const AST::WhileLoopExpression &node);
};

#endif
