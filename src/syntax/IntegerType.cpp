#include "IntegerType.h"

Node::IntegerType::IntegerType() = default;

void Node::IntegerType::accept(Visitor &visitor) {
  std::shared_ptr<IntegerType> p{shared_from_this()};

  visitor.accept(p);
}
