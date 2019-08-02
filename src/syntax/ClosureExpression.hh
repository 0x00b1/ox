#ifndef OXC_CLOSURE_EXPRESSION_HH
#define OXC_CLOSURE_EXPRESSION_HH

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Expression.hh"
#include "Visitor.hh"

class Node::ClosureExpression: public Expression, public std::enable_shared_from_this<ClosureExpression> {
public:
  ClosureExpression(std::shared_ptr<FunctionDeclaration> declaration, std::shared_ptr<Expression> expression);

  std::shared_ptr<FunctionDeclaration> declaration;

  std::shared_ptr<Expression> expression;

  void accept(Visitor &visitor) override;
};

#endif
