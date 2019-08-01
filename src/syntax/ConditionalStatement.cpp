#include "ConditionalStatement.hh"

Node::ConditionalStatement::ConditionalStatement(std::string value) {
  this->value = std::move(value);
}

void Node::ConditionalStatement::accept(Visitor &visitor) {
  std::shared_ptr<ConditionalStatement> p{shared_from_this()};

  visitor.accept(p);
}
