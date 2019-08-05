#include "Pattern.h"

Node::Pattern::Pattern(std::shared_ptr<Node> node) {
  this->node = std::move(node);
}

void Node::Pattern::accept(Visitor &visitor) {
  std::shared_ptr<Pattern> p{shared_from_this()};

  visitor.accept(p);
}