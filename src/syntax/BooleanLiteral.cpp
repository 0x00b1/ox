#include "BooleanLiteral.hh"

Node::BooleanLiteral::BooleanLiteral(bool value) {
  this->value = std::move(value);
};

void Node::BooleanLiteral::accept(Visitor &visitor) {
  std::shared_ptr<BooleanLiteral> p{shared_from_this()};

  visitor.accept(p);
}
