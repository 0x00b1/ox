#include "ConditionalStatement.h"

Node::ConditionalStatement::ConditionalStatement(std::shared_ptr<Expression> predicate, std::shared_ptr<BlockStatement> consequent) {
  this->predicate = std::move(predicate);

  this->consequent = std::move(consequent);
}

Node::ConditionalStatement::ConditionalStatement(std::shared_ptr<Expression> predicate, std::shared_ptr<BlockStatement> consequent, std::optional<std::shared_ptr<BlockStatement>> alternate) {
  this->predicate = std::move(predicate);

  this->consequent = std::move(consequent);

  this->alternate = std::move(alternate);
}

void Node::ConditionalStatement::accept(Visitor &visitor) {
  std::shared_ptr<ConditionalStatement> p{shared_from_this()};

  visitor.accept(p);
}
