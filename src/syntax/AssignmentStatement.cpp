#include "AssignmentStatement.h"

Node::AssignmentStatement::AssignmentStatement(std::shared_ptr<Pattern> pattern, std::shared_ptr<Type> type, std::shared_ptr<Expression> expression) {
  this->pattern = std::move(pattern);

  this->type = std::move(type);

  this->expression = std::move(expression);
}

void Node::AssignmentStatement::accept(Visitor &visitor) {
  std::shared_ptr<AssignmentStatement> p{shared_from_this()};

  visitor.accept(p);
}
