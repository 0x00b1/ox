#ifndef OX_GENERATOR_H
#define OX_GENERATOR_H

#include <memory>

#include "syntax/syntax.h"

class Generator: public Visitor {
public:
  virtual void accept(std::shared_ptr<Node::AnonymousConstant> node) override;
  virtual void accept(std::shared_ptr<Node::Argument> node) override;
  virtual void accept(std::shared_ptr<Node::ArrayExpression> node) override;
  virtual void accept(std::shared_ptr<Node::ArrayType> node) override;
  virtual void accept(std::shared_ptr<Node::AssignmentStatement> node) override;
  virtual void accept(std::shared_ptr<Node::BlockStatement> node) override;
  virtual void accept(std::shared_ptr<Node::BooleanLiteralExpression> node) override;
  virtual void accept(std::shared_ptr<Node::BooleanType> node) override;
  virtual void accept(std::shared_ptr<Node::BottomType> node) override;
  virtual void accept(std::shared_ptr<Node::CallExpression> node) override;
  virtual void accept(std::shared_ptr<Node::ClosureExpression> node) override;
  virtual void accept(std::shared_ptr<Node::ConditionalStatement> node) override;
  virtual void accept(std::shared_ptr<Node::ConstantItem> node) override;
  virtual void accept(std::shared_ptr<Node::Expression> node) override;
  virtual void accept(std::shared_ptr<Node::ExpressionStatement> node) override;
  virtual void accept(std::shared_ptr<Node::ExternalPackageItem> node) override;
  virtual void accept(std::shared_ptr<Node::FloatingPointLiteralExpression> node) override;
  virtual void accept(std::shared_ptr<Node::FloatingPointType> node) override;
  virtual void accept(std::shared_ptr<Node::FunctionDeclaration> node) override;
  virtual void accept(std::shared_ptr<Node::FunctionType> node) override;
  virtual void accept(std::shared_ptr<Node::GroupedExpression> node) override;
  virtual void accept(std::shared_ptr<Node::Identifier> node) override;
  virtual void accept(std::shared_ptr<Node::IdentifierPattern> node) override;
  virtual void accept(std::shared_ptr<Node::IndexExpression> node) override;
  virtual void accept(std::shared_ptr<Node::InfixExpression> node) override;
  virtual void accept(std::shared_ptr<Node::IntegerLiteralExpression> node) override;
  virtual void accept(std::shared_ptr<Node::IntegerType> node) override;
  virtual void accept(std::shared_ptr<Node::Item> node) override;
  virtual void accept(std::shared_ptr<Node::ItemStatement> node) override;
  virtual void accept(std::shared_ptr<Node::Literal> node) override;
  virtual void accept(std::shared_ptr<Node::LiteralExpression> node) override;
  virtual void accept(std::shared_ptr<Node::LiteralPattern> node) override;
  virtual void accept(std::shared_ptr<Node::ModuleItem> node) override;
  virtual void accept(std::shared_ptr<Node::Name> node) override;
  virtual void accept(std::shared_ptr<Node::OperatorExpression> node) override;
  virtual void accept(std::shared_ptr<Node::Parameter> node) override;
  virtual void accept(std::shared_ptr<Node::PathExpression> node) override;
  virtual void accept(std::shared_ptr<Node::PathPattern> node) override;
  virtual void accept(std::shared_ptr<Node::PathType> node) override;
  virtual void accept(std::shared_ptr<Node::Pattern> node) override;
  virtual void accept(std::shared_ptr<Node::PointerType> node) override;
  virtual void accept(std::shared_ptr<Node::PostfixExpression> node) override;
  virtual void accept(std::shared_ptr<Node::PrefixExpression> node) override;
  virtual void accept(std::shared_ptr<Node::ReferencePattern> node) override;
  virtual void accept(std::shared_ptr<Node::ReferenceType> node) override;
  virtual void accept(std::shared_ptr<Node::ReturnStatement> node) override;
  virtual void accept(std::shared_ptr<Node::SizeType> node) override;
  virtual void accept(std::shared_ptr<Node::SlicePattern> node) override;
  virtual void accept(std::shared_ptr<Node::SliceType> node) override;
  virtual void accept(std::shared_ptr<Node::Statement> node) override;
  virtual void accept(std::shared_ptr<Node::SubroutineItem> node) override;
  virtual void accept(std::shared_ptr<Node::TupleExpression> node) override;
  virtual void accept(std::shared_ptr<Node::TuplePattern> node) override;
  virtual void accept(std::shared_ptr<Node::TupleType> node) override;
  virtual void accept(std::shared_ptr<Node::Type> node) override;
  virtual void accept(std::shared_ptr<Node::TypeItem> node) override;
  virtual void accept(std::shared_ptr<Node::Unit> node) override;
  virtual void accept(std::shared_ptr<Node::WildcardPattern> node) override;
};

#endif
