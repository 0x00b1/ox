#include "PrefixExpression.h"

Node::PrefixExpression::PrefixExpression(std::shared_ptr<PostfixExpression> expression) {
  this->expression = std::move(expression);
}

Node::PrefixExpression::PrefixExpression(Operator operation, std::shared_ptr<PostfixExpression> expression) {
  this->operation = std::move(operation);

  this->expression = std::move(expression);
}

void Node::PrefixExpression::accept(Visitor &visitor) {
  std::shared_ptr<PrefixExpression> p{shared_from_this()};

  visitor.accept(p);
}
