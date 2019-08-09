#include "InfixOperation.h"

Node::InfixOperation::InfixOperation() = default;

void Node::InfixOperation::accept(Visitor &visitor) {
  std::shared_ptr<InfixOperation> p{shared_from_this()};

  visitor.accept(p);
}
