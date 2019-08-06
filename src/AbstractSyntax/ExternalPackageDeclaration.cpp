#include "ExternalPackageDeclaration.h"

Node::ExternalPackageDeclaration::ExternalPackageDeclaration(std::string identifier) {
  this->identifier = std::move(identifier);
}

Node::ExternalPackageDeclaration::ExternalPackageDeclaration(std::string identifier, std::string alias) {
  this->identifier = std::move(identifier);

  this->alias = std::move(alias);
}

void Node::ExternalPackageDeclaration::accept(Visitor &visitor) {
  std::shared_ptr<ExternalPackageDeclaration> p{shared_from_this()};

  visitor.accept(p);
}
