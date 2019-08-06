#include "IndexExpression.h"

Node::IndexExpression::IndexExpression(std::shared_ptr<Node> container, std::shared_ptr<Node> index) {
  this->container = std::move(container);

  this->container = std::move(index);
}

void Node::IndexExpression::accept(Visitor &visitor) {
  std::shared_ptr<IndexExpression> p{shared_from_this()};

  visitor.accept(p);
}
