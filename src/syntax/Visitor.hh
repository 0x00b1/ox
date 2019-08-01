#ifndef OX_VISITOR_HH
#define OX_VISITOR_HH

#include <memory>

class Visitor;

namespace Node {
  class Node {
  public:
    virtual void accept(Visitor &visitor) = 0;
  };
}

namespace Node {
  class AnonymousConstant;
  class Argument;
  class ArrayExpression;
  class ArrayType;
  class AssignmentStatement;
  class BlockStatement;
  class BooleanLiteral;
  class BooleanType;
  class BottomType;
  class CallExpression;
  class ConditionalStatement;
  class ConstantItem;
  class Expression;
  class ExpressionStatement;
  class FloatingPointLiteral;
  class FloatingPointType;
  class FunctionDeclaration;
  class FunctionType;
  class Identifier;
  class IndexExpression;
  class IntegerLiteral;
  class IntegerType;
  class Item;
  class ItemStatement;
  class Literal;
  class LiteralExpression;
  class Name;
  class Parameter;
  class PathType;
  class Pattern;
  class PointerType;
  class ReferenceType;
  class ReturnStatement;
  class SliceType;
  class Statement;
  class SubroutineItem;
  class Type;
}

class Visitor {
public:
  virtual void accept(std::shared_ptr<Node::AnonymousConstant>) = 0;
  virtual void accept(std::shared_ptr<Node::Argument>) = 0;
  virtual void accept(std::shared_ptr<Node::ArrayExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::ArrayType>) = 0;
  virtual void accept(std::shared_ptr<Node::AssignmentStatement>) = 0;
  virtual void accept(std::shared_ptr<Node::BlockStatement>) = 0;
  virtual void accept(std::shared_ptr<Node::BooleanLiteral>) = 0;
  virtual void accept(std::shared_ptr<Node::BooleanType>) = 0;
  virtual void accept(std::shared_ptr<Node::BottomType>) = 0;
  virtual void accept(std::shared_ptr<Node::CallExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::ConditionalStatement>) = 0;
  virtual void accept(std::shared_ptr<Node::ConstantItem>) = 0;
  virtual void accept(std::shared_ptr<Node::Expression>) = 0;
  virtual void accept(std::shared_ptr<Node::ExpressionStatement>) = 0;
  virtual void accept(std::shared_ptr<Node::FloatingPointLiteral>) = 0;
  virtual void accept(std::shared_ptr<Node::FloatingPointType>) = 0;
  virtual void accept(std::shared_ptr<Node::FunctionDeclaration>) = 0;
  virtual void accept(std::shared_ptr<Node::FunctionType>) = 0;
  virtual void accept(std::shared_ptr<Node::Identifier>) = 0;
  virtual void accept(std::shared_ptr<Node::IndexExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::IntegerLiteral>) = 0;
  virtual void accept(std::shared_ptr<Node::IntegerType>) = 0;
  virtual void accept(std::shared_ptr<Node::Item>) = 0;
  virtual void accept(std::shared_ptr<Node::ItemStatement>) = 0;
  virtual void accept(std::shared_ptr<Node::Literal>) = 0;
  virtual void accept(std::shared_ptr<Node::LiteralExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::Name>) = 0;
  virtual void accept(std::shared_ptr<Node::Parameter>) = 0;
  virtual void accept(std::shared_ptr<Node::PathType>) = 0;
  virtual void accept(std::shared_ptr<Node::Pattern>) = 0;
  virtual void accept(std::shared_ptr<Node::PointerType>) = 0;
  virtual void accept(std::shared_ptr<Node::ReferenceType>) = 0;
  virtual void accept(std::shared_ptr<Node::ReturnStatement>) = 0;
  virtual void accept(std::shared_ptr<Node::SliceType>) = 0;
  virtual void accept(std::shared_ptr<Node::Statement>) = 0;
  virtual void accept(std::shared_ptr<Node::SubroutineItem>) = 0;
  virtual void accept(std::shared_ptr<Node::Type>) = 0;
};

#endif
