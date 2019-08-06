#include "SliceType.h"

Node::SliceType::SliceType(std::shared_ptr<Type> type) {
  this->type = std::move(type);
}

void Node::SliceType::accept(Visitor &visitor) {
  std::shared_ptr<SliceType> p{shared_from_this()};

  visitor.accept(p);
}
