#ifndef OXC_GROUPED_EXPRESSION_H
#define OXC_GROUPED_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "OperatorExpression.h"
#include "Visitor/Visitor.h"

class Node::GroupedExpression: public Node, public std::enable_shared_from_this<GroupedExpression> {
public:
  explicit GroupedExpression(std::shared_ptr<OperatorExpression> operator_expression);

  std::shared_ptr<OperatorExpression> operator_expression;

  void accept(Visitor &visitor) override;
};

#endif
