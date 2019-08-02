#include "FunctionType.h"

Node::FunctionType::FunctionType() = default;

void Node::FunctionType::accept(Visitor &visitor) {
  std::shared_ptr<FunctionType> p{shared_from_this()};

  visitor.accept(p);
}
