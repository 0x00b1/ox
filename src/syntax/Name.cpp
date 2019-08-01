#include "Name.hh"

Node::Name::Name(std::string value) {
  this->value = std::move(value);
}

void Node::Name::accept(Visitor &visitor) {
  std::shared_ptr<Name> p{shared_from_this()};

  visitor.accept(p);
}
