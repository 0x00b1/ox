#include "PathPattern.h"

Node::PathPattern::PathPattern(std::shared_ptr<Path> path) {
  this->path = std::move(path);
}

void Node::PathPattern::accept(Visitor &visitor) {
  std::shared_ptr<PathPattern> p{shared_from_this()};

  visitor.accept(p);
}
