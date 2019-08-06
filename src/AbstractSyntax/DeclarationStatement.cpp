#include "DeclarationStatement.h"

Node::DeclarationStatement::DeclarationStatement(std::shared_ptr<Declaration> item) {
  this->item = std::move(item);
}

void Node::DeclarationStatement::accept(Visitor &visitor) {
  std::shared_ptr<DeclarationStatement> p{shared_from_this()};

  visitor.accept(p);
}
