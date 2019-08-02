#include "PathType.h"

Node::PathType::PathType() = default;

void Node::PathType::accept(Visitor &visitor) {
  std::shared_ptr<PathType> p{shared_from_this()};

  visitor.accept(p);
}
