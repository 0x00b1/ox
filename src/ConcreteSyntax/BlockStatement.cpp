#include "BlockStatement.h"

Node::BlockStatement::BlockStatement(std::vector<std::shared_ptr<Statement>> statements) {
  this->statements = std::move(statements);
}

void Node::BlockStatement::accept(Visitor &visitor) {
  std::shared_ptr<BlockStatement> p{shared_from_this()};

  visitor.accept(p);
}
