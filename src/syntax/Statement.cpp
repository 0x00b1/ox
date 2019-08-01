#include "Statement.hh"

Node::Statement::Statement(std::string value) {
  this->value = std::move(value);
}

void Node::Statement::accept(Visitor &visitor) {
  std::shared_ptr<Statement> p{shared_from_this()};

  visitor.accept(p);
}
