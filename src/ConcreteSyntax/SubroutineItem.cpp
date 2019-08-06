#include "SubroutineItem.h"

Node::SubroutineItem::SubroutineItem(std::string identifier, std::shared_ptr<FunctionType> function_type, std::shared_ptr<BlockStatement> block_statement) {
  this->identifier = std::move(identifier);

  this->function_type = std::move(function_type);

  this->block_statement = std::move(block_statement);
}

void Node::SubroutineItem::accept(Visitor &visitor) {
  std::shared_ptr<SubroutineItem> p{shared_from_this()};

  visitor.accept(p);
}
