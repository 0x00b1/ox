#ifndef OXC_EXPRESSION_STATEMENT_H
#define OXC_EXPRESSION_STATEMENT_H

#include <memory>
#include <string>
#include <utility>

#include "OperatorExpression.h"
#include "Statement.h"
#include "Visitor/Visitor.h"

class Node::ExpressionStatement: public Node, public std::enable_shared_from_this<ExpressionStatement> {
public:
  explicit ExpressionStatement(std::shared_ptr<OperatorExpression> expression);

  std::shared_ptr<OperatorExpression> expression;

  void accept(Visitor &visitor) override;
};

#endif