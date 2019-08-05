#ifndef OXC_INFIX_OPERATOR_EXPRESSION_H
#define OXC_INFIX_OPERATOR_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "PrefixExpression.h"
#include "Visitor.h"

class Node::InfixExpression: public Node, public std::enable_shared_from_this<InfixExpression> {
public:
  InfixExpression(Operator operation, std::shared_ptr<PrefixExpression> expression);

  std::shared_ptr<PrefixExpression> expression;

  Operator operation;

  void accept(Visitor &visitor) override;
};

#endif
