#include "ImportDeclaration.h"

Node::ImportDeclaration::ImportDeclaration() = default;

void Node::ImportDeclaration::accept(Visitor &visitor) {
  std::shared_ptr<ImportDeclaration> p{shared_from_this()};

  visitor.accept(p);
}
