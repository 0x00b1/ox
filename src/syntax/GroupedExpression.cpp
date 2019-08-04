#include "GroupedExpression.h"

Node::GroupedExpression::GroupedExpression(std::shared_ptr<Expression> expression) {
  this->expression = std::move(expression);
}

void Node::GroupedExpression::accept(Visitor &visitor) {
  std::shared_ptr<GroupedExpression> p{shared_from_this()};

  visitor.accept(p);
}
