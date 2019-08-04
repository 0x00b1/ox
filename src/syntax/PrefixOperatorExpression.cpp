#include "PrefixOperatorExpression.h"

Node::PrefixOperatorExpression::PrefixOperatorExpression() = default;

void Node::PrefixOperatorExpression::accept(Visitor &visitor) {
  std::shared_ptr<PrefixOperatorExpression> p{shared_from_this()};

  visitor.accept(p);
}
