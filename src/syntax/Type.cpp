#include "Type.h"

Node::Type::Type(std::shared_ptr<Node> node) {
  this->node = std::move(node);
}

void Node::Type::accept(Visitor &visitor) {
  std::shared_ptr<Type> p{shared_from_this()};

  visitor.accept(p);
}
