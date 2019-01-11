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
    virtual void visit(AST::Argument &file) = 0;
    virtual void visit(AST::ArrayExpression &file) = 0;
    virtual void visit(AST::BinaryOperationExpression &file) = 0;
    virtual void visit(AST::BlockExpression &file) = 0;
    virtual void visit(AST::BooleanLiteralExpression &file) = 0;
    virtual void visit(AST::BreakExpression &file) = 0;
    virtual void visit(AST::CallExpression &file) = 0;
    virtual void visit(AST::ClosureExpression &file) = 0;
    virtual void visit(AST::ConditionalExpression &file) = 0;
    virtual void visit(AST::ConstantDeclaration &file) = 0;
    virtual void visit(AST::ContinueExpression &file) = 0;
    virtual void visit(AST::EnumerationDeclaration &file) = 0;
    virtual void visit(AST::FloatingPointLiteralExpression &file) = 0;
    virtual void visit(AST::ForLoopExpression &file) = 0;
    virtual void visit(AST::GenericParameter &file) = 0;
    virtual void visit(AST::IntegerLiteralExpression &file) = 0;
    virtual void visit(AST::LabelDeclaration &file) = 0;
    virtual void visit(AST::ModuleDeclaration &file) = 0;
    virtual void visit(AST::Node &node) = 0;
    virtual void visit(AST::Parameter &file) = 0;
    virtual void visit(AST::RangeExpression &file) = 0;
    virtual void visit(AST::RecordDeclaration &file) = 0;
    virtual void visit(AST::RecordExpression &file) = 0;
    virtual void visit(AST::RecordFieldDeclaration &file) = 0;
    virtual void visit(AST::ReturnExpression &file) = 0;
    virtual void visit(AST::Root &file) = 0;
    virtual void visit(AST::SubroutineDeclaration &file) = 0;
    virtual void visit(AST::SubscriptExpression &file) = 0;
    virtual void visit(AST::SwitchExpression &file) = 0;
    virtual void visit(AST::TupleExpression &file) = 0;
    virtual void visit(AST::TypeAliasDeclaration &file) = 0;
    virtual void visit(AST::TypeSignature &file) = 0;
    virtual void visit(AST::UnaryOperationExpression &file) = 0;
    virtual void visit(AST::UnionDeclaration &file) = 0;
    virtual void visit(AST::WhileLoopExpression &file) = 0;
};

#endif
