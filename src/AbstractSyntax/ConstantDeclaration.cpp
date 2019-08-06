#include "ConstantDeclaration.h"

Node::ConstantDeclaration::ConstantDeclaration(std::string identifier, std::shared_ptr<Type> type, std::shared_ptr<Node> expression) {
  this->identifier = std::move(identifier);

  this->type = std::move(type);

  this->expression = std::move(expression);
}

void Node::ConstantDeclaration::accept(Visitor &visitor) {
  std::shared_ptr<ConstantDeclaration> p{shared_from_this()};

  visitor.accept(p);
}
