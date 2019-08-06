#include "Path.h"

Node::Path::Path() = default;

void Node::Path::accept(Visitor &visitor) {
  std::shared_ptr<Path> p{shared_from_this()};

  visitor.accept(p);
}
