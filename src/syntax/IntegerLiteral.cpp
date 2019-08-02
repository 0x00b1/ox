#include "IntegerLiteral.h"

Node::IntegerLiteral::IntegerLiteral(std::string value) {
  this->value = std::move(value);
}

void Node::IntegerLiteral::accept(Visitor &visitor) {
  std::shared_ptr<IntegerLiteral> p{shared_from_this()};

  visitor.accept(p);
}
