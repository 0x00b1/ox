#include "ArrayType.h"

Node::ArrayType::ArrayType(std::shared_ptr<Type> type, std::shared_ptr<AnonymousConstant> anonymous_constant) {
  this->type = std::move(type);

  this->anonymous_constant = std::move(anonymous_constant);
}

void Node::ArrayType::accept(Visitor &visitor) {
  std::shared_ptr<ArrayType> p{shared_from_this()};

  visitor.accept(p);
}
