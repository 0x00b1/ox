#include "ReferenceType.hh"

Node::ReferenceType::ReferenceType() = default;

void Node::ReferenceType::accept(Visitor &visitor) {
  std::shared_ptr<ReferenceType> p{shared_from_this()};

  visitor.accept(p);
}
