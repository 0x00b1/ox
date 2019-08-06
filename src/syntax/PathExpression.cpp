#include "PathExpression.h"

Node::PathExpression::PathExpression(std::string identifier) {
  this->identifier = std::move(identifier);
}

void Node::PathExpression::accept(Visitor &visitor) {
  std::shared_ptr<PathExpression> p{shared_from_this()};

  visitor.accept(p);
}
