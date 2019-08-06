#include "ReturnStatement.h"

Node::ReturnStatement::ReturnStatement() {}

Node::ReturnStatement::ReturnStatement(std::shared_ptr<Node> expression) {
  this->expression = std::move(expression);
}

void Node::ReturnStatement::accept(Visitor &visitor) {
  std::shared_ptr<ReturnStatement> p{shared_from_this()};

  visitor.accept(p);
}
