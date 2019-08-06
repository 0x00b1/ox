#include "ModuleDeclaration.h"

Node::ModuleDeclaration::ModuleDeclaration() = default;

Node::ModuleDeclaration::ModuleDeclaration(std::vector<std::shared_ptr<Declaration>> items) {
  this->items = std::move(items);
}

void Node::ModuleDeclaration::accept(Visitor &visitor) {
  std::shared_ptr<ModuleDeclaration> p{shared_from_this()};

  visitor.accept(p);
}
