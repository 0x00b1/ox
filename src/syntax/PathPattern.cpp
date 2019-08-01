#include "PathPattern.hh"

Node::PathPattern::PathPattern() {}

void Node::PathPattern::accept(Visitor &visitor) {
  std::shared_ptr<PathPattern> p{shared_from_this()};

  visitor.accept(p);
}
