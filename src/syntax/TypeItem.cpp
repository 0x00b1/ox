#include "TypeItem.h"

Node::TypeItem::TypeItem() = default;

void Node::TypeItem::accept(Visitor &visitor) {
  std::shared_ptr<TypeItem> p{shared_from_this()};

  visitor.accept(p);
}
