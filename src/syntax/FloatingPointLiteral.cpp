#include "FloatingPointLiteral.h"

Node::FloatingPointLiteral::FloatingPointLiteral(std::string value) {
  this->value = std::move(value);
}

void Node::FloatingPointLiteral::accept(Visitor &visitor) {
  std::shared_ptr<FloatingPointLiteral> p{shared_from_this()};

  visitor.accept(p);
}
