#include "TypeItem.h"

Node::TypeItem::TypeItem(std::string identifier, std::shared_ptr<Type> type) {
  this->identifier = std::move(identifier);

  this->type = std::move(type);
}

void Node::TypeItem::accept(Visitor &visitor) {
  std::shared_ptr<TypeItem> p{shared_from_this()};

  visitor.accept(p);
}
