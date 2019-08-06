#include "PrefixExpression.h"

Node::PrefixExpression::PrefixExpression(std::shared_ptr<PostfixExpression> postfix_expression) {
  this->postfix_expression = std::move(postfix_expression);
}

Node::PrefixExpression::PrefixExpression(std::string operation, std::shared_ptr<PostfixExpression> postfix_expression) {
  this->operation = std::move(operation);

  this->postfix_expression = std::move(postfix_expression);
}

void Node::PrefixExpression::accept(Visitor &visitor) {
  std::shared_ptr<PrefixExpression> p{shared_from_this()};

  visitor.accept(p);
}
