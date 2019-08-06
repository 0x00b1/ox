#include "ItemStatement.h"

Node::ItemStatement::ItemStatement(std::shared_ptr<Item> item) {
  this->item = std::move(item);
}

void Node::ItemStatement::accept(Visitor &visitor) {
  std::shared_ptr<ItemStatement> p{shared_from_this()};

  visitor.accept(p);
}
