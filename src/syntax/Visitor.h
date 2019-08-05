#ifndef OX_VISITOR_H
#define OX_VISITOR_H

#include <memory>

#include "Node.h"

namespace Node {
  class AnonymousConstant;
  class Argument;
  class ArrayExpression;
  class ArrayType;
  class AssignmentStatement;
  class BlockStatement;
  class BooleanLiteralExpression;
  class BooleanType;
  class BottomType;
  class CallExpression;
  class ClosureExpression;
  class ConditionalStatement;
  class ConstantItem;
  class Expression;
  class ExpressionStatement;
  class ExternalPackageItem;
  class FloatingPointLiteralExpression;
  class FloatingPointType;
  class FunctionDeclaration;
  class FunctionType;
  class GroupedExpression;
  class Identifier;
  class IndexExpression;
  class InfixExpression;
  class IntegerLiteralExpression;
  class IntegerType;
  class Item;
  class ItemStatement;
  class Literal;
  class LiteralExpression;
  class LiteralPattern;
  class ModuleItem;
  class Name;
  class OperatorExpression;
  class Parameter;
  class PathExpression;
  class PathPattern;
  class PathType;
  class Pattern;
  class PointerType;
  class PostfixExpression;
  class PrefixExpression;
  class ReferencePattern;
  class ReferenceType;
  class ReturnStatement;
  class SizeType;
  class SlicePattern;
  class SliceType;
  class Statement;
  class SubroutineItem;
  class TupleExpression;
  class TuplePattern;
  class TupleType;
  class Type;
  class TypeItem;
  class Unit;
  class WildcardPattern;
}

class Visitor {
public:
  virtual void accept(std::shared_ptr<Node::AnonymousConstant>) = 0;
  virtual void accept(std::shared_ptr<Node::Argument>) = 0;
  virtual void accept(std::shared_ptr<Node::ArrayExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::ArrayType>) = 0;
  virtual void accept(std::shared_ptr<Node::AssignmentStatement>) = 0;
  virtual void accept(std::shared_ptr<Node::BlockStatement>) = 0;
  virtual void accept(std::shared_ptr<Node::BooleanLiteralExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::BooleanType>) = 0;
  virtual void accept(std::shared_ptr<Node::BottomType>) = 0;
  virtual void accept(std::shared_ptr<Node::CallExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::ClosureExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::ConditionalStatement>) = 0;
  virtual void accept(std::shared_ptr<Node::ConstantItem>) = 0;
  virtual void accept(std::shared_ptr<Node::Expression>) = 0;
  virtual void accept(std::shared_ptr<Node::ExpressionStatement>) = 0;
  virtual void accept(std::shared_ptr<Node::ExternalPackageItem>) = 0;
  virtual void accept(std::shared_ptr<Node::FloatingPointLiteralExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::FloatingPointType>) = 0;
  virtual void accept(std::shared_ptr<Node::FunctionDeclaration>) = 0;
  virtual void accept(std::shared_ptr<Node::FunctionType>) = 0;
  virtual void accept(std::shared_ptr<Node::GroupedExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::Identifier>) = 0;
  virtual void accept(std::shared_ptr<Node::IndexExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::InfixExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::IntegerLiteralExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::IntegerType>) = 0;
  virtual void accept(std::shared_ptr<Node::Item>) = 0;
  virtual void accept(std::shared_ptr<Node::ItemStatement>) = 0;
  virtual void accept(std::shared_ptr<Node::Literal>) = 0;
  virtual void accept(std::shared_ptr<Node::LiteralExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::LiteralPattern>) = 0;
  virtual void accept(std::shared_ptr<Node::ModuleItem>) = 0;
  virtual void accept(std::shared_ptr<Node::Name>) = 0;
  virtual void accept(std::shared_ptr<Node::OperatorExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::Parameter>) = 0;
  virtual void accept(std::shared_ptr<Node::PathExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::PathPattern>) = 0;
  virtual void accept(std::shared_ptr<Node::PathType>) = 0;
  virtual void accept(std::shared_ptr<Node::Pattern>) = 0;
  virtual void accept(std::shared_ptr<Node::PointerType>) = 0;
  virtual void accept(std::shared_ptr<Node::PostfixExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::PrefixExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::ReferencePattern>) = 0;
  virtual void accept(std::shared_ptr<Node::ReferenceType>) = 0;
  virtual void accept(std::shared_ptr<Node::ReturnStatement>) = 0;
  virtual void accept(std::shared_ptr<Node::SizeType>) = 0;
  virtual void accept(std::shared_ptr<Node::SlicePattern>) = 0;
  virtual void accept(std::shared_ptr<Node::SliceType>) = 0;
  virtual void accept(std::shared_ptr<Node::Statement>) = 0;
  virtual void accept(std::shared_ptr<Node::SubroutineItem>) = 0;
  virtual void accept(std::shared_ptr<Node::TupleExpression>) = 0;
  virtual void accept(std::shared_ptr<Node::TuplePattern>) = 0;
  virtual void accept(std::shared_ptr<Node::TupleType>) = 0;
  virtual void accept(std::shared_ptr<Node::Type>) = 0;
  virtual void accept(std::shared_ptr<Node::TypeItem>) = 0;
  virtual void accept(std::shared_ptr<Node::Unit>) = 0;
  virtual void accept(std::shared_ptr<Node::WildcardPattern>) = 0;
};

#endif
