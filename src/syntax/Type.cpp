#include "Type.hh"

Node::Type::Type(std::string value) {
  this->value = std::move(value);
}

void Node::Type::accept(Visitor &visitor) {
  std::shared_ptr<Type> p{shared_from_this()};

  visitor.accept(p);
}
