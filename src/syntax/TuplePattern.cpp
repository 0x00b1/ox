#include "TuplePattern.h"

Node::TuplePattern::TuplePattern(std::vector<std::shared_ptr<Pattern>> patterns) {
  this->patterns = std::move(patterns);
}

void Node::TuplePattern::accept(Visitor &visitor) {
  std::shared_ptr<TuplePattern> p{shared_from_this()};

  visitor.accept(p);
}
