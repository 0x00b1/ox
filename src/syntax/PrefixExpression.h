#ifndef OXC_PREFIX_OPERATOR_EXPRESSION_H
#define OXC_PREFIX_OPERATOR_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "Visitor.h"

class Node::PrefixExpression: public Expression, public std::enable_shared_from_this<PrefixExpression> {
public:
  PrefixExpression();

  void accept(Visitor &visitor) override;
};

#endif
