#include "Declaration.h"

Node::Declaration::Declaration(std::shared_ptr<Node> node) {
  this->node = std::move(node);
}

void Node::Declaration::accept(Visitor &visitor) {
  std::shared_ptr<Declaration> p{shared_from_this()};

  visitor.accept(p);
}
