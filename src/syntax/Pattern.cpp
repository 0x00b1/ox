#include "Pattern.hh"

Node::Pattern::Pattern(std::string value) {
  this->value = std::move(value);
}

void Node::Pattern::accept(Visitor &visitor) {
  std::shared_ptr<Pattern> p{shared_from_this()};

  visitor.accept(p);
}
