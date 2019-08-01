#include "ArrayType.hh"

Node::ArrayType::ArrayType() = default;

void Node::ArrayType::accept(Visitor &visitor) {
  std::shared_ptr<ArrayType> p{shared_from_this()};

  visitor.accept(p);
}
