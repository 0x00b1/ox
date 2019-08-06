#include "FunctionPrototype.h"

Node::FunctionPrototype::FunctionPrototype(std::vector<std::shared_ptr<Parameter>> parameters, std::shared_ptr<Type> return_type) {
  this->parameters = std::move(parameters);

  this->return_type = std::move(return_type);
};

void Node::FunctionPrototype::accept(Visitor &visitor) {
  std::shared_ptr<FunctionPrototype> p{shared_from_this()};

  visitor.accept(p);
}
