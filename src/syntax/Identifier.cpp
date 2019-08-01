#include "Identifier.hh"


Node::Identifier::Identifier(std::string value) {
  this->value = std::move(value);
}

void Node::Identifier::accept(Visitor &visitor) {
  std::shared_ptr<Identifier> p{shared_from_this()};

  visitor.accept(p);
}
