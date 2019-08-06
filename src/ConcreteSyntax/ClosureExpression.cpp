#include "ClosureExpression.h"

Node::ClosureExpression::ClosureExpression(std::shared_ptr<FunctionDeclaration> declaration, std::shared_ptr<Expression> expression) {
  this->declaration = std::move(declaration);

  this->expression = std::move(expression);
}

void Node::ClosureExpression::accept(Visitor &visitor) {
  std::shared_ptr<ClosureExpression> p{shared_from_this()};

  visitor.accept(p);
}
