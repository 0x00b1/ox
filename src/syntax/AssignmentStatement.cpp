#include "AssignmentStatement.hh"


Node::AssignmentStatement::AssignmentStatement(std::string value) {
  this->value = std::move(value);
}

void Node::AssignmentStatement::accept(Visitor &visitor) {
  std::shared_ptr<AssignmentStatement> p{shared_from_this()};

  visitor.accept(p);
}
