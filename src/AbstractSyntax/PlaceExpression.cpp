#include "PlaceExpression.h"

Node::PlaceExpression::PlaceExpression(std::shared_ptr<Node> node) {
  this->node = std::move(node);
}

void Node::PlaceExpression::accept(Visitor &visitor) {
  std::shared_ptr<PlaceExpression> p{shared_from_this()};

  visitor.accept(p);
}
