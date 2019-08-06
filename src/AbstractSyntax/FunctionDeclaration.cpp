#include "FunctionDeclaration.h"

Node::FunctionDeclaration::FunctionDeclaration(std::shared_ptr<FunctionPrototype> function_prototype) {
  this->function_prototype = std::move(function_prototype);
};

void Node::FunctionDeclaration::accept(Visitor &visitor) {
  std::shared_ptr<FunctionDeclaration> p{shared_from_this()};

  visitor.accept(p);
}
