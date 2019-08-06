#include "WildcardPattern.h"

Node::WildcardPattern::WildcardPattern() {}

void Node::WildcardPattern::accept(Visitor &visitor) {
  std::shared_ptr<WildcardPattern> p{shared_from_this()};

  visitor.accept(p);
}
