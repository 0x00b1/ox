#include "BooleanLiteral.hh"

Node::BooleanLiteral::BooleanLiteral() = default;

void Node::BooleanLiteral::accept(Visitor &visitor) {
  std::shared_ptr<BooleanLiteral> p{shared_from_this()};

  visitor.accept(p);
}
