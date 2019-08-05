#include "ReferenceType.h"

Node::ReferenceType::ReferenceType(std::shared_ptr<Type> type) {
  this->type = std::move(type);
}

void Node::ReferenceType::accept(Visitor &visitor) {
  std::shared_ptr<ReferenceType> p{shared_from_this()};

  visitor.accept(p);
}
