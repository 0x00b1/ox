#include "InfixExpression.h"

Node::InfixExpression::InfixExpression(Operator operation, std::shared_ptr<PrefixExpression> expression) {
  this->operation = std::move(operation);

  this->expression = std::move(expression);
}

void Node::InfixExpression::accept(Visitor &visitor) {
  std::shared_ptr<InfixExpression> p{shared_from_this()};

  visitor.accept(p);
}
