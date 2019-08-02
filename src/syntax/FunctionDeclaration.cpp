#include "FunctionDeclaration.h"

Node::FunctionDeclaration::FunctionDeclaration() = default;

void Node::FunctionDeclaration::accept(Visitor &visitor) {
  std::shared_ptr<FunctionDeclaration> p{shared_from_this()};

  visitor.accept(p);
}
