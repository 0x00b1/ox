#include "TupleExpression.h"

Node::TupleExpression::TupleExpression(std::vector<std::shared_ptr<Node>> elements) {
  this->elements = std::move(elements);
}

void Node::TupleExpression::accept(Visitor &visitor) {
  std::shared_ptr<TupleExpression> p{shared_from_this()};

  visitor.accept(p);
}
