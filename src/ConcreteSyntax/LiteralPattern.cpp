#include "LiteralPattern.h"

Node::LiteralPattern::LiteralPattern(std::shared_ptr<Expression> expression) {
  this->expression = std::move(expression);
};

void Node::LiteralPattern::accept(Visitor &visitor) {
  std::shared_ptr<LiteralPattern> p{shared_from_this()};

  visitor.accept(p);
}
