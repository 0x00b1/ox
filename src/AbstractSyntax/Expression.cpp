#include "Expression.h"

Node::Expression::Expression(std::shared_ptr<Node> node) {
  this->node = std::move(node);
}

void Node::Expression::accept(Visitor &visitor) {
  std::shared_ptr<Expression> p{shared_from_this()};

  visitor.accept(p);
}
