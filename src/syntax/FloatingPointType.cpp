#include "FloatingPointType.hh"

Node::FloatingPointType::FloatingPointType() = default;

void Node::FloatingPointType::accept(Visitor &visitor) {
  std::shared_ptr<FloatingPointType> p{shared_from_this()};

  visitor.accept(p);
}
