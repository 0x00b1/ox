#include "PointerType.hh"

Node::PointerType::PointerType() = default;

void Node::PointerType::accept(Visitor &visitor) {
  std::shared_ptr<PointerType> p{shared_from_this()};

  visitor.accept(p);
}
