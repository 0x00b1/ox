#include "Identifier.hh"

Node::Identifier::Identifier() = default;

void Node::Identifier::accept(Visitor &visitor) {
  std::shared_ptr<Identifier> p{shared_from_this()};

  visitor.accept(p);
}
