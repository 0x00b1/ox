#include "PathExpression.h"

Node::PathExpression::PathExpression(std::vector<std::shared_ptr<Expression>> elements) {
  this->elements = std::move(elements);
}

void Node::PathExpression::accept(Visitor &visitor) {
  std::shared_ptr<PathExpression> p{shared_from_this()};

  visitor.accept(p);
}
