#include "Identifier.h"

Node::Identifier::Identifier(std::string name) {
  this->name = std::move(name);
};

void Node::Identifier::accept(Visitor &visitor) {
  std::shared_ptr<Identifier> p{shared_from_this()};

  visitor.accept(p);
}
