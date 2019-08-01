#include "FloatingPointLiteral.hh"

Node::FloatingPointLiteral::FloatingPointLiteral() = default;

void Node::FloatingPointLiteral::accept(Visitor &visitor) {
  std::shared_ptr<FloatingPointLiteral> p{shared_from_this()};

  visitor.accept(p);
}
