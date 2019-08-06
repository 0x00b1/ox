#include "ModuleDeclaration.h"

Node::ModuleDeclaration::ModuleDeclaration(std::string identifier) {
  this->identifier = std::move(identifier);
}

Node::ModuleDeclaration::ModuleDeclaration(std::string identifier, std::vector<std::shared_ptr<Declaration>> items) {
  this->identifier = std::move(identifier);

  this->items = std::move(items);
}

void Node::ModuleDeclaration::accept(Visitor &visitor) {
  std::shared_ptr<ModuleDeclaration> p{shared_from_this()};

  visitor.accept(p);
}
