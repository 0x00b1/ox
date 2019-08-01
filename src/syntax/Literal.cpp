#include "Literal.hh"


Node::Literal::Literal(std::string value) {
  this->value = std::move(value);
}

void Node::Literal::accept(Visitor &visitor) {
  std::shared_ptr<Literal> p{shared_from_this()};

  visitor.accept(p);
}
