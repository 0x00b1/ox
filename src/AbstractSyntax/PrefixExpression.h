#ifndef OXC_PREFIX_OPERATOR_EXPRESSION_H
#define OXC_PREFIX_OPERATOR_EXPRESSION_H

#include <memory>
#include <optional>
#include <string>
#include <utility>

#include "Expression.h"
#include "Operator.h"
#include "PostfixExpression.h"
#include "Visitor/Visitor.h"

class Node::PrefixExpression: public Node, public std::enable_shared_from_this<PrefixExpression> {
public:
  explicit PrefixExpression(std::shared_ptr<PostfixExpression> postfix_expression);

  PrefixExpression(std::string operation, std::shared_ptr<PostfixExpression> postfix_expression);

  std::shared_ptr<PostfixExpression> postfix_expression;

  std::optional<std::string> operation;

  void accept(Visitor &visitor) override;
};

#endif
