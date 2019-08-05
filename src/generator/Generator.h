#ifndef OX_GENERATOR_H
#define OX_GENERATOR_H

#include <memory>

#include "syntax/syntax.h"

class Generator: public Visitor {
public:
  void accept(std::shared_ptr<Node::AnonymousConstant> node) override;
  void accept(std::shared_ptr<Node::Argument> node) override;
  void accept(std::shared_ptr<Node::ArrayExpression> node) override;
  void accept(std::shared_ptr<Node::ArrayType> node) override;
  void accept(std::shared_ptr<Node::AssignmentStatement> node) override;
  void accept(std::shared_ptr<Node::BlockStatement> node) override;
  void accept(std::shared_ptr<Node::BooleanLiteralExpression> node) override;
  void accept(std::shared_ptr<Node::BooleanType> node) override;
  void accept(std::shared_ptr<Node::BottomType> node) override;
  void accept(std::shared_ptr<Node::CallExpression> node) override;
  void accept(std::shared_ptr<Node::ClosureExpression> node) override;
  void accept(std::shared_ptr<Node::ConditionalStatement> node) override;
  void accept(std::shared_ptr<Node::ConstantItem> node) override;
  void accept(std::shared_ptr<Node::ExpressionStatement> node) override;
  void accept(std::shared_ptr<Node::ExternalPackageItem> node) override;
  void accept(std::shared_ptr<Node::FloatingPointLiteralExpression> node) override;
  void accept(std::shared_ptr<Node::FloatingPointType> node) override;
  void accept(std::shared_ptr<Node::FunctionDeclaration> node) override;
  void accept(std::shared_ptr<Node::FunctionType> node) override;
  void accept(std::shared_ptr<Node::GroupedExpression> node) override;
  void accept(std::shared_ptr<Node::Identifier> node) override;
  void accept(std::shared_ptr<Node::IndexExpression> node) override;
  void accept(std::shared_ptr<Node::InfixExpression> node) override;
  void accept(std::shared_ptr<Node::IntegerLiteralExpression> node) override;
  void accept(std::shared_ptr<Node::IntegerType> node) override;
  void accept(std::shared_ptr<Node::ItemStatement> node) override;
  void accept(std::shared_ptr<Node::Literal> node) override;
  void accept(std::shared_ptr<Node::LiteralExpression> node) override;
  void accept(std::shared_ptr<Node::LiteralPattern> node) override;
  void accept(std::shared_ptr<Node::ModuleItem> node) override;
  void accept(std::shared_ptr<Node::Name> node) override;
  void accept(std::shared_ptr<Node::OperatorExpression> node) override;
  void accept(std::shared_ptr<Node::Parameter> node) override;
  void accept(std::shared_ptr<Node::PathExpression> node) override;
  void accept(std::shared_ptr<Node::PathPattern> node) override;
  void accept(std::shared_ptr<Node::PathType> node) override;
  void accept(std::shared_ptr<Node::PointerType> node) override;
  void accept(std::shared_ptr<Node::PostfixExpression> node) override;
  void accept(std::shared_ptr<Node::PrefixExpression> node) override;
  void accept(std::shared_ptr<Node::ReferencePattern> node) override;
  void accept(std::shared_ptr<Node::ReferenceType> node) override;
  void accept(std::shared_ptr<Node::ReturnStatement> node) override;
  void accept(std::shared_ptr<Node::SizeType> node) override;
  void accept(std::shared_ptr<Node::SlicePattern> node) override;
  void accept(std::shared_ptr<Node::SliceType> node) override;
  void accept(std::shared_ptr<Node::SubroutineItem> node) override;
  void accept(std::shared_ptr<Node::TupleExpression> node) override;
  void accept(std::shared_ptr<Node::TuplePattern> node) override;
  void accept(std::shared_ptr<Node::TupleType> node) override;
  void accept(std::shared_ptr<Node::TypeItem> node) override;
  void accept(std::shared_ptr<Node::Unit> node) override;
  void accept(std::shared_ptr<Node::WildcardPattern> node) override;
};

#endif
