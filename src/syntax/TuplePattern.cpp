#include "TuplePattern.hh"

Node::TuplePattern::TuplePattern() {}

void Node::TuplePattern::accept(Visitor &visitor) {
  std::shared_ptr<TuplePattern> p{shared_from_this()};

  visitor.accept(p);
}
