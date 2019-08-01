#include "CallExpression.hh"


Node::CallExpression::CallExpression(
    std::shared_ptr<Expression> subroutine,
    std::vector<std::shared_ptr<Expression>> parameters
) {
  this->subroutine = std::move(subroutine);

  this->parameters = std::move(parameters);
}

void Node::CallExpression::accept(Visitor &visitor) {
  std::shared_ptr<CallExpression> p{shared_from_this()};

  visitor.accept(p);
}
