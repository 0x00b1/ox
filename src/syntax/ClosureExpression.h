#ifndef OXC_CLOSURE_EXPRESSION_H
#define OXC_CLOSURE_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Expression.h"
#include "Visitor.h"

class Node::ClosureExpression: public Expression, public std::enable_shared_from_this<ClosureExpression> {
public:
  ClosureExpression(std::shared_ptr<FunctionDeclaration> declaration, std::shared_ptr<Expression> expression);

  std::shared_ptr<FunctionDeclaration> declaration;

  std::shared_ptr<Expression> expression;

  void accept(Visitor &visitor) override;
};

#endif
