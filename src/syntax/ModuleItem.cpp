#include "ModuleItem.h"

Node::ModuleItem::ModuleItem() = default;

void Node::ModuleItem::accept(Visitor &visitor) {
  std::shared_ptr<ModuleItem> p{shared_from_this()};

  visitor.accept(p);
}
