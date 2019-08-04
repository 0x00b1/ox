#include "BooleanLiteralExpression.h"

Node::BooleanLiteralExpression::BooleanLiteralExpression(bool value) {
  this->value = std::move(value);
};

void Node::BooleanLiteralExpression::accept(Visitor &visitor) {
  std::shared_ptr<BooleanLiteralExpression> p{shared_from_this()};

  visitor.accept(p);
}
