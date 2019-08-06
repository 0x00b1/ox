#include "SizeType.h"

Node::SizeType::SizeType() = default;

void Node::SizeType::accept(Visitor &visitor) {
  std::shared_ptr<SizeType> p{shared_from_this()};

  visitor.accept(p);
}
