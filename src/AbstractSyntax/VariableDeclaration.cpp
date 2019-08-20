#include "VariableDeclaration.h"

Node::VariableDeclaration::VariableDeclaration(std::shared_ptr<Pattern> pattern) {
  this->pattern = std::move(pattern);
}

Node::VariableDeclaration::VariableDeclaration(std::shared_ptr<Pattern> pattern, std::shared_ptr<Type> type) {
  this->pattern = std::move(pattern);

  this->type = std::move(type);
}

Node::VariableDeclaration::VariableDeclaration(std::shared_ptr<Pattern> pattern, std::shared_ptr<Node> expression) {
  this->pattern = std::move(pattern);

  this->expression = std::move(expression);
}

Node::VariableDeclaration::VariableDeclaration(std::shared_ptr<Pattern> pattern, std::shared_ptr<Type> type, std::shared_ptr<Node> expression) {
  this->pattern = std::move(pattern);

  this->type = std::move(type);

  this->expression = std::move(expression);
}

void Node::VariableDeclaration::accept(Visitor &visitor) {
  std::shared_ptr<VariableDeclaration> p{shared_from_this()};

  visitor.accept(p);
}
