#ifndef OXC_LITERAL_PATTERN_H
#define OXC_LITERAL_PATTERN_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "OperatorExpression.h"
#include "Pattern.h"

class Node::LiteralPattern: public Node, public std::enable_shared_from_this<LiteralPattern> {
public:
  explicit LiteralPattern(std::shared_ptr<OperatorExpression> expression);

  std::shared_ptr<OperatorExpression> expression;

  void accept(Visitor &visitor) override;
};

#endif
