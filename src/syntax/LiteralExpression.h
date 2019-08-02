#ifndef OXC_LITERAL_EXPRESSION_H
#define OXC_LITERAL_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "Visitor.h"

class Node::LiteralExpression: public Expression, public std::enable_shared_from_this<LiteralExpression> {
public:
  explicit LiteralExpression(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
