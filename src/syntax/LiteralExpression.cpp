#include "LiteralExpression.h"

Node::LiteralExpression::LiteralExpression(std::string value) {
  this->value = std::move(value);
}

void Node::LiteralExpression::accept(Visitor &visitor) {
  std::shared_ptr<LiteralExpression> p{shared_from_this()};

  visitor.accept(p);
}
