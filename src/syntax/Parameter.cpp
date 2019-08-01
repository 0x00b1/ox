#include "Parameter.hh"


Node::Parameter::Parameter(std::string value) {
  this->value = std::move(value);
}

void Node::Parameter::accept(Visitor &visitor) {
  std::shared_ptr<Parameter> p{shared_from_this()};

  visitor.accept(p);
}
