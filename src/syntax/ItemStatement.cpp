#include "ItemStatement.h"

Node::ItemStatement::ItemStatement(std::string value) {
  this->value = std::move(value);
}

void Node::ItemStatement::accept(Visitor &visitor) {
  std::shared_ptr<ItemStatement> p{shared_from_this()};

  visitor.accept(p);
}
