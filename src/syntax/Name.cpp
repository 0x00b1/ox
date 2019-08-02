#include "Name.h"

Node::Name::Name() = default;

void Node::Name::accept(Visitor &visitor) {
  std::shared_ptr<Name> p{shared_from_this()};

  visitor.accept(p);
}
