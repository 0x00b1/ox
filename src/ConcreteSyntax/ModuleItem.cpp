#include "ModuleItem.h"

Node::ModuleItem::ModuleItem(std::string identifier) {
  this->identifier = std::move(identifier);
}

Node::ModuleItem::ModuleItem(std::string identifier, std::vector<std::shared_ptr<Item>> items) {
  this->identifier = std::move(identifier);

  this->items = std::move(items);
}

void Node::ModuleItem::accept(Visitor &visitor) {
  std::shared_ptr<ModuleItem> p{shared_from_this()};

  visitor.accept(p);
}
