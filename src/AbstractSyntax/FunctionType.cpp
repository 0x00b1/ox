#include "FunctionType.h"

Node::FunctionType::FunctionType(std::shared_ptr<FunctionDeclaration> function_declaration) {
  this->function_declaration = std::move(function_declaration);
}

void Node::FunctionType::accept(Visitor &visitor) {
  std::shared_ptr<FunctionType> p{shared_from_this()};

  visitor.accept(p);
}
