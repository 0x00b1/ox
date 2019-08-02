#include "ExpressionStatement.h"

Node::ExpressionStatement::ExpressionStatement(std::shared_ptr<Expression> expression) {
  this->expression = std::move(expression);
}

void Node::ExpressionStatement::accept(Visitor &visitor) {
  std::shared_ptr<ExpressionStatement> p{shared_from_this()};

  visitor.accept(p);
}
