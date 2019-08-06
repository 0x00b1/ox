#include "PathType.h"

Node::PathType::PathType(std::shared_ptr<Path> path) {
  this->path = std::move(path);
};

void Node::PathType::accept(Visitor &visitor) {
  std::shared_ptr<PathType> p{shared_from_this()};

  visitor.accept(p);
}
