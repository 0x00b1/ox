#include "BottomType.hh"

Node::BottomType::BottomType() = default;

void Node::BottomType::accept(Visitor &visitor) {
  std::shared_ptr<BottomType> p{shared_from_this()};

  visitor.accept(p);
}
