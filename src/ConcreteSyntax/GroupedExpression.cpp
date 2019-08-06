#include "GroupedExpression.h"

Node::GroupedExpression::GroupedExpression(std::shared_ptr<OperatorExpression> operator_expression) {
  this->operator_expression = std::move(operator_expression);
}

void Node::GroupedExpression::accept(Visitor &visitor) {
  std::shared_ptr<GroupedExpression> p{shared_from_this()};

  visitor.accept(p);
}
