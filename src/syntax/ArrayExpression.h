#ifndef OXC_ARRAY_EXPRESSION_H
#define OXC_ARRAY_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Expression.h"
#include "Visitor.h"

class Node::ArrayExpression: public Expression, public std::enable_shared_from_this<ArrayExpression> {
public:
  explicit ArrayExpression(std::vector<std::shared_ptr<Expression>> elements);

  std::vector<std::shared_ptr<Expression>> elements;

  void accept(Visitor &visitor) override;
};

#endif
