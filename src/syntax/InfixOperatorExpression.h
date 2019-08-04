#ifndef OXC_INFIX_OPERATOR_EXPRESSION_H
#define OXC_INFIX_OPERATOR_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "Visitor.h"

class Node::InfixOperatorExpression: public Expression, public std::enable_shared_from_this<InfixOperatorExpression> {
public:
  InfixOperatorExpression();

  void accept(Visitor &visitor) override;
};

#endif
