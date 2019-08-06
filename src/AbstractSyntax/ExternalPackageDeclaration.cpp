#include "ExternalPackageDeclaration.h"

Node::ExternalPackageDeclaration::ExternalPackageDeclaration() = default;

void Node::ExternalPackageDeclaration::accept(Visitor &visitor) {
  std::shared_ptr<ExternalPackageDeclaration> p{shared_from_this()};

  visitor.accept(p);
}
