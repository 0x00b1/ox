#include "PostfixOperatorExpression.h"

Node::PostfixOperatorExpression::PostfixOperatorExpression() = default;

void Node::PostfixOperatorExpression::accept(Visitor &visitor) {
  std::shared_ptr<PostfixOperatorExpression> p{shared_from_this()};

  visitor.accept(p);
}
