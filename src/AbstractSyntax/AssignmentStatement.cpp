#include "AssignmentStatement.h"

Node::AssignmentStatement::AssignmentStatement(std::shared_ptr<PlaceExpression> place_expression, std::shared_ptr<ValueExpression> value_expression) {
  this->place_expression = std::move(place_expression);

  this->value_expression = std::move(value_expression);
}

void Node::AssignmentStatement::accept(Visitor &visitor) {
  std::shared_ptr<AssignmentStatement> p{shared_from_this()};

  visitor.accept(p);
}
