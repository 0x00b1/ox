#ifndef OXC_CALL_EXPRESSION_H
#define OXC_CALL_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Expression.h"
#include "Visitor.h"

class Node::CallExpression: public Expression, public std::enable_shared_from_this<CallExpression> {
public:
  CallExpression(std::shared_ptr<Expression> subroutine, std::vector<std::shared_ptr<Expression>> parameters);

  std::shared_ptr<Expression> subroutine;

  std::vector<std::shared_ptr<Expression>> parameters;

  void accept(Visitor &visitor) override;
};

#endif