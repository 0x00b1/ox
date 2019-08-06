#include "FunctionPrototype.h"

Node::FunctionPrototype::FunctionPrototype() = default;

void Node::FunctionPrototype::accept(Visitor &visitor) {
  std::shared_ptr<FunctionPrototype> p{shared_from_this()};

  visitor.accept(p);
}
