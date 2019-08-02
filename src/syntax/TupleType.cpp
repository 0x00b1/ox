#include "TupleType.h"

Node::TupleType::TupleType(std::vector<std::shared_ptr<Type>> types) {
  this->types = std::move(types);
};

void Node::TupleType::accept(Visitor &visitor) {
  std::shared_ptr<TupleType> p{shared_from_this()};

  visitor.accept(p);
}
