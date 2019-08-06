#include "OperatorExpression.h"

Node::OperatorExpression::OperatorExpression(std::shared_ptr<PrefixExpression> prefix_expression, std::vector<std::shared_ptr<InfixExpression>> infix_expressions) {
  this->prefix_expression = std::move(prefix_expression);

  this->infix_expressions = std::move(infix_expressions);
}

Node::OperatorExpression::OperatorExpression(std::shared_ptr<PrefixExpression> prefix_expression) {
  this->prefix_expression = std::move(prefix_expression);
}

void Node::OperatorExpression::accept(Visitor &visitor) {
  std::shared_ptr<OperatorExpression> p{shared_from_this()};

  visitor.accept(p);
}
