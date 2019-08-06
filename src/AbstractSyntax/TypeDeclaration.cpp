#include "TypeDeclaration.h"

Node::TypeDeclaration::TypeDeclaration(std::shared_ptr<Type> type) {
  this->type = std::move(type);
}

void Node::TypeDeclaration::accept(Visitor &visitor) {
  std::shared_ptr<TypeDeclaration> p{shared_from_this()};

  visitor.accept(p);
}
