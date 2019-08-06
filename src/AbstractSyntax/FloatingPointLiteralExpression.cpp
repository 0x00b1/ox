#include "FloatingPointLiteralExpression.h"

Node::FloatingPointLiteralExpression::FloatingPointLiteralExpression(std::string value) {
  this->value = std::move(value);
}

void Node::FloatingPointLiteralExpression::accept(Visitor &visitor) {
  std::shared_ptr<FloatingPointLiteralExpression> p{shared_from_this()};

  visitor.accept(p);
}
