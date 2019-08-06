#include "PathSegment.h"

Node::PathSegment::PathSegment(std::shared_ptr<Identifier> identifier) {
  this->identifier = std::move(identifier);
}

void Node::PathSegment::accept(Visitor &visitor) {
  std::shared_ptr<PathSegment> p{shared_from_this()};

  visitor.accept(p);
}
