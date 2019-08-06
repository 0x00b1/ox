#ifndef OXC_OPERATOR_EXPRESSION_H
#define OXC_OPERATOR_EXPRESSION_H

#include <memory>
#include <optional>
#include <string>
#include <utility>
#include <vector>

#include "Expression.h"
#include "InfixExpression.h"
#include "PrefixExpression.h"
#include "Visitor/Visitor.h"

class Node::OperatorExpression: public Node, public std::enable_shared_from_this<OperatorExpression> {
public:
  OperatorExpression(std::shared_ptr<PrefixExpression> prefix_expression, std::vector<std::shared_ptr<InfixExpression>> infix_expressions);

  explicit OperatorExpression(std::shared_ptr<PrefixExpression> prefix_expression);

  std::shared_ptr<PrefixExpression> prefix_expression;

  std::vector<std::shared_ptr<InfixExpression>> infix_expressions;

  void accept(Visitor &visitor) override;
};

#endif
