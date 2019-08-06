#include "PostfixExpression.h"

Node::PostfixExpression::PostfixExpression(std::shared_ptr<Node> expression) {
  this->expression = std::move(expression);
}

void Node::PostfixExpression::accept(Visitor &visitor) {
  std::shared_ptr<PostfixExpression> p{shared_from_this()};

  visitor.accept(p);
}
