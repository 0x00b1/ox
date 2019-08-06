#include "FunctionType.h"

Node::FunctionType::FunctionType(std::vector<std::shared_ptr<Parameter>> parameters, std::shared_ptr<Type> return_type) {
  this->parameters = std::move(parameters);

  this->return_type = std::move(return_type);
}

void Node::FunctionType::accept(Visitor &visitor) {
  std::shared_ptr<FunctionType> p{shared_from_this()};

  visitor.accept(p);
}
