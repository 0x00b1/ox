#include "InfixExpression.h"

Node::InfixExpression::InfixExpression() = default;

void Node::InfixExpression::accept(Visitor &visitor) {
  std::shared_ptr<InfixExpression> p{shared_from_this()};

  visitor.accept(p);
}
