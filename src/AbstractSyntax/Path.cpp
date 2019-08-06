#include "Path.h"

Node::Path::Path(std::vector<std::shared_ptr<PathSegment>> path_segments) {
  this->path_segments = std::move(path_segments);
}

void Node::Path::accept(Visitor &visitor) {
  std::shared_ptr<Path> p{shared_from_this()};

  visitor.accept(p);
}
