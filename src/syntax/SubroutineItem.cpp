#include "SubroutineItem.hh"

Node::SubroutineItem::SubroutineItem(std::shared_ptr<FunctionDeclaration> declaration, std::shared_ptr<BlockStatement> block_statement) {
  this->declaration = std::move(declaration);

  this->block_statement = std::move(block_statement);
}

void Node::SubroutineItem::accept(Visitor &visitor) {
  std::shared_ptr<SubroutineItem> p{shared_from_this()};

  visitor.accept(p);
}
