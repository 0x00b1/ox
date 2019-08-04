#ifndef OXC_PREFIX_OPERATOR_EXPRESSION_H
#define OXC_PREFIX_OPERATOR_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "Visitor.h"

class Node::PrefixOperatorExpression: public Expression, public std::enable_shared_from_this<PrefixOperatorExpression> {
public:
  PrefixOperatorExpression();

  void accept(Visitor &visitor) override;
};

#endif
