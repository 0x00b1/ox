#include "FunctionType.hh"

Node::FunctionType::FunctionType(std::shared_ptr<FunctionDeclaration> declaration) {
  this->declaration = std::move(declaration);
}

void Node::FunctionType::accept(Visitor &visitor) {
  std::shared_ptr<FunctionType> p{shared_from_this()};

  visitor.accept(p);
}


