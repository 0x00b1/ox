#include "ConstantItem.h"

Node::ConstantItem::ConstantItem(std::string identifier, std::shared_ptr<Type> type, std::shared_ptr<Expression> expression) {
  this->identifier = std::move(identifier);

  this->type = std::move(type);

  this->expression = std::move(expression);
}

void Node::ConstantItem::accept(Visitor &visitor) {
  std::shared_ptr<ConstantItem> p{shared_from_this()};

  visitor.accept(p);
}
