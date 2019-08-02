#include "TupleExpression.hh"

Node::TupleExpression::TupleExpression(std::vector<std::shared_ptr<Expression>> elements) {
  this->elements = std::move(elements);
}

void Node::TupleExpression::accept(Visitor &visitor) {
  std::shared_ptr<TupleExpression> p{shared_from_this()};

  visitor.accept(p);
}
