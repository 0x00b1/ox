#include "Expression.hh"


Node::Expression::Expression() {}

void Node::Expression::accept(Visitor &visitor) {
  std::shared_ptr<Expression> p{shared_from_this()};

  visitor.accept(p);
}
