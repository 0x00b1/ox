#include "IdentifierPattern.h"

Node::IdentifierPattern::IdentifierPattern(std::shared_ptr<Identifier> identifier) {
  this->identifier = std::move(identifier);
}

void Node::IdentifierPattern::accept(Visitor &visitor) {
  std::shared_ptr<IdentifierPattern> p{shared_from_this()};

  visitor.accept(p);
}
