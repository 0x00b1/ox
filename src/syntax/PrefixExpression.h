#ifndef OXC_PREFIX_OPERATOR_EXPRESSION_H
#define OXC_PREFIX_OPERATOR_EXPRESSION_H

#include <memory>
#include <optional>
#include <string>
#include <utility>

#include "Expression.h"
#include "Operator.h"
#include "Visitor.h"

class Node::PrefixExpression: public Expression, public std::enable_shared_from_this<PrefixExpression> {
public:
  explicit PrefixExpression(std::shared_ptr<Expression> expression);

  PrefixExpression(Operator operation, std::shared_ptr<Expression> expression);

  std::shared_ptr<Expression> expression;

  std::optional<Operator> operation;

  void accept(Visitor &visitor) override;
};

#endif
