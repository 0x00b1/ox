#include "SliceType.h"

Node::SliceType::SliceType() = default;

void Node::SliceType::accept(Visitor &visitor) {
  std::shared_ptr<SliceType> p{shared_from_this()};

  visitor.accept(p);
}
