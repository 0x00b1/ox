#ifndef OXC_POSTFIX_OPERATOR_EXPRESSION_H
#define OXC_POSTFIX_OPERATOR_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "Visitor.h"

class Node::PostfixOperatorExpression: public Expression, public std::enable_shared_from_this<PostfixOperatorExpression> {
public:
  PostfixOperatorExpression();

  void accept(Visitor &visitor) override;
};

#endif
