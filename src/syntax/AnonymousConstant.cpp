#include "AnonymousConstant.hh"

Node::AnonymousConstant::AnonymousConstant(std::shared_ptr<Expression> expression) {
  this->expression = std::move(expression);
}

void Node::AnonymousConstant::accept(Visitor &visitor) {
  std::shared_ptr<AnonymousConstant> p{shared_from_this()};

  visitor.accept(p);
}
