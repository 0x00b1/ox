#include "Item.h"

Node::Item::Item(std::shared_ptr<Node> node) {
  this->node = std::move(node);
}

void Node::Item::accept(Visitor &visitor) {
  std::shared_ptr<Item> p{shared_from_this()};

  visitor.accept(p);
}
