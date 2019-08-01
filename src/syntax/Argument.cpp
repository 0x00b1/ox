#include "Argument.hh"

Node::Argument::Argument(std::shared_ptr<Pattern> pattern, std::shared_ptr<Type> type) {
  this->pattern = std::move(pattern);

  this->type = std::move(type);
}

void Node::Argument::accept(Visitor &visitor) {
  std::shared_ptr<Argument> p{shared_from_this()};

  visitor.accept(p);
}
