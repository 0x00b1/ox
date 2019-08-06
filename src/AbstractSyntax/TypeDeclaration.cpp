#include "TypeDeclaration.h"

Node::TypeDeclaration::TypeDeclaration(std::string identifier, std::shared_ptr<Type> type) {
  this->identifier = std::move(identifier);

  this->type = std::move(type);
}

void Node::TypeDeclaration::accept(Visitor &visitor) {
  std::shared_ptr<TypeDeclaration> p{shared_from_this()};

  visitor.accept(p);
}
