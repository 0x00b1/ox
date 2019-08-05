#ifndef OXC_POSTFIX_OPERATOR_EXPRESSION_H
#define OXC_POSTFIX_OPERATOR_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "Visitor.h"

class Node::PostfixExpression: public Node, public std::enable_shared_from_this<PostfixExpression> {
public:
  explicit PostfixExpression(std::shared_ptr<Expression> expression);

  std::shared_ptr<Expression> expression;

  void accept(Visitor &visitor) override;
};

#endif
