#include "ArrayExpression.h"

Node::ArrayExpression::ArrayExpression(std::vector<std::shared_ptr<Node>> elements) {
  this->elements = std::move(elements);
}

void Node::ArrayExpression::accept(Visitor &visitor) {
  std::shared_ptr<ArrayExpression> p{shared_from_this()};

  visitor.accept(p);
}
