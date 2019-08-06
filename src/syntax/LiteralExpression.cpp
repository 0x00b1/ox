#include "LiteralExpression.h"

Node::LiteralExpression::LiteralExpression(std::shared_ptr<Node> node) {
  this->node = std::move(node);
}

void Node::LiteralExpression::accept(Visitor &visitor) {
  std::shared_ptr<LiteralExpression> p{shared_from_this()};

  visitor.accept(p);
}
