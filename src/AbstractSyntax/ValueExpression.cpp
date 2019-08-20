#include "ValueExpression.h"

Node::ValueExpression::ValueExpression(std::shared_ptr<Node> node) {
  this->node = std::move(node);
}

void Node::ValueExpression::accept(Visitor &visitor) {
  std::shared_ptr<ValueExpression> p{shared_from_this()};

  visitor.accept(p);
}
