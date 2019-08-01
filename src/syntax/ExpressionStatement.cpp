#include "ExpressionStatement.hh"

Node::ExpressionStatement::ExpressionStatement(std::string value) {
  this->value = std::move(value);
}

void Node::ExpressionStatement::accept(Visitor &visitor) {
  std::shared_ptr<ExpressionStatement> p{shared_from_this()};

  visitor.accept(p);
}
