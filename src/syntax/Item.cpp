#include "Item.hh"

Node::Item::Item(std::string value) {
  this->value = std::move(value);
}

void Node::Item::accept(Visitor &visitor) {
  std::shared_ptr<Item> p{shared_from_this()};

  visitor.accept(p);
}
