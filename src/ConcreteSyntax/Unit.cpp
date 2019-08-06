#include "Unit.h"

Node::Unit::Unit(std::vector<std::shared_ptr<Statement>> statements) {
  this->statements = std::move(statements);
}

void Node::Unit::accept(Visitor &visitor) {
  std::shared_ptr<Unit> p{shared_from_this()};

  visitor.accept(p);
}
