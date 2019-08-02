#include "ArrayType.h"

Node::ArrayType::ArrayType(std::shared_ptr<Type> type) {
  this->type = std::move(type);
};

void Node::ArrayType::accept(Visitor &visitor) {
  std::shared_ptr<ArrayType> p{shared_from_this()};

  visitor.accept(p);
}
