#ifndef OX_GENERATOR_HH
#define OX_GENERATOR_HH

#include <memory>

#include "syntax/Visitor.hh"

class Generator: public Visitor {
public:
  void accept(std::shared_ptr<Node::Argument> node) override;
  void accept(std::shared_ptr<Node::ArrayExpression> node) override;
  void accept(std::shared_ptr<Node::AssignmentStatement> node) override;
  void accept(std::shared_ptr<Node::BlockStatement> node) override;
  void accept(std::shared_ptr<Node::CallExpression> node) override;
  void accept(std::shared_ptr<Node::ConditionalStatement> node) override;
  void accept(std::shared_ptr<Node::ConstantItem> node) override;
  void accept(std::shared_ptr<Node::Expression> node) override;
  void accept(std::shared_ptr<Node::ExpressionStatement> node) override;
  void accept(std::shared_ptr<Node::Identifier> node) override;
  void accept(std::shared_ptr<Node::IndexExpression> node) override;
  void accept(std::shared_ptr<Node::Item> node) override;
  void accept(std::shared_ptr<Node::ItemStatement> node) override;
  void accept(std::shared_ptr<Node::Literal> node) override;
  void accept(std::shared_ptr<Node::LiteralExpression> node) override;
  void accept(std::shared_ptr<Node::Name> node) override;
  void accept(std::shared_ptr<Node::Parameter> node) override;
  void accept(std::shared_ptr<Node::Pattern> node) override;
  void accept(std::shared_ptr<Node::ReturnStatement> node) override;
  void accept(std::shared_ptr<Node::SubroutineItem> node) override;
  void accept(std::shared_ptr<Node::Type> node) override;
};

#endif
