#include "Statement.h"

Node::Statement::Statement(std::shared_ptr<Node> node) {
  this->node = std::move(node);
}

void Node::Statement::accept(Visitor &visitor) {
  std::shared_ptr<Statement> p{shared_from_this()};

  visitor.accept(p);
}
