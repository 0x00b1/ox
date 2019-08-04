#include "PrefixExpression.h"

Node::PrefixExpression::PrefixExpression() = default;

void Node::PrefixExpression::accept(Visitor &visitor) {
  std::shared_ptr<PrefixExpression> p{shared_from_this()};

  visitor.accept(p);
}
