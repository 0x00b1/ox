#include "ClassDeclaration.h"

Node::ClassDeclaration::ClassDeclaration() = default;

void Node::ClassDeclaration::accept(Visitor &visitor) {
  std::shared_ptr<ClassDeclaration> p{shared_from_this()};

  visitor.accept(p);
}
