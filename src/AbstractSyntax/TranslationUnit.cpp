#include "TranslationUnit.h"

Node::TranslationUnit::TranslationUnit(std::vector<std::shared_ptr<Statement>> statements) {
  this->statements = std::move(statements);
}

void Node::TranslationUnit::accept(Visitor &visitor) {
  std::shared_ptr<TranslationUnit> p{shared_from_this()};

  visitor.accept(p);
}
