#include "Parameter.h"

Node::Parameter::Parameter(std::string pattern, std::shared_ptr<Type> type) {
  this->pattern = std::move(pattern);

  this->type = std::move(type);
}

void Node::Parameter::accept(Visitor &visitor) {
  std::shared_ptr<Parameter> p{shared_from_this()};

  visitor.accept(p);
}
