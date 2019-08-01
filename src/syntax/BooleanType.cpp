#include "BooleanType.hh"

Node::BooleanType::BooleanType() = default;

void Node::BooleanType::accept(Visitor &visitor) {
  std::shared_ptr<BooleanType> p{shared_from_this()};

  visitor.accept(p);
}
