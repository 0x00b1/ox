#include "ReferencePattern.h"

Node::ReferencePattern::ReferencePattern(std::shared_ptr<Pattern> pattern) {
  this->pattern = std::move(pattern);
}

void Node::ReferencePattern::accept(Visitor &visitor) {
  std::shared_ptr<ReferencePattern> p{shared_from_this()};

  visitor.accept(p);
}
