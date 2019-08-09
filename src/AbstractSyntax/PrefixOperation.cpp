#include "PrefixOperation.h"

Node::PrefixOperation::PrefixOperation() = default;

void Node::PrefixOperation::accept(Visitor &visitor) {
  std::shared_ptr<PrefixOperation> p{shared_from_this()};

  visitor.accept(p);
}
