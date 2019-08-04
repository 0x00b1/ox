#include "PostfixExpression.h"

Node::PostfixExpression::PostfixExpression() = default;

void Node::PostfixExpression::accept(Visitor &visitor) {
  std::shared_ptr<PostfixExpression> p{shared_from_this()};

  visitor.accept(p);
}
