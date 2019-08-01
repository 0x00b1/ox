#include "SubroutineItem.hh"

Node::SubroutineItem::SubroutineItem(std::vector<Argument> arguments, std::shared_ptr<Type> type, std::shared_ptr<BlockStatement> block_statement) {
  this->arguments = std::move(arguments);

  this->type = std::move(type);

  this->block_statement = std::move(block_statement);
}

void Node::SubroutineItem::accept(Visitor &visitor) {
  std::shared_ptr<SubroutineItem> p{shared_from_this()};

  visitor.accept(p);
}
