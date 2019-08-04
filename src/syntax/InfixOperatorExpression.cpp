#include "InfixOperatorExpression.h"

Node::InfixOperatorExpression::InfixOperatorExpression() = default;

void Node::InfixOperatorExpression::accept(Visitor &visitor) {
  std::shared_ptr<InfixOperatorExpression> p{shared_from_this()};

  visitor.accept(p);
}
