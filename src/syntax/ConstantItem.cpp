#include "ConstantItem.h"

Node::ConstantItem::ConstantItem(std::string value) {
  this->value = std::move(value);
}

void Node::ConstantItem::accept(Visitor &visitor) {
  std::shared_ptr<ConstantItem> p{shared_from_this()};

  visitor.accept(p);
}
