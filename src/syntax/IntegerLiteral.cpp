#include "IntegerLiteral.hh"

Node::IntegerLiteral::IntegerLiteral() = default;

void Node::IntegerLiteral::accept(Visitor &visitor) {
  std::shared_ptr<IntegerLiteral> p{shared_from_this()};

  visitor.accept(p);
}
