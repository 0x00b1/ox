#include "IntegerLiteralExpression.h"

Node::IntegerLiteralExpression::IntegerLiteralExpression(std::string value) {
  this->value = std::move(value);
}

void Node::IntegerLiteralExpression::accept(Visitor &visitor) {
  std::shared_ptr<IntegerLiteralExpression> p{shared_from_this()};

  visitor.accept(p);
}
