#ifndef OXC_LITERAL_PATTERN_H
#define OXC_LITERAL_PATTERN_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "Pattern.h"
#include "Visitor/Visitor.h"

class Node::LiteralPattern: public Node, public std::enable_shared_from_this<LiteralPattern> {
public:
  explicit LiteralPattern(std::shared_ptr<Expression> expression);

  std::shared_ptr<Expression> expression;

  void accept(Visitor &visitor) override;
};

#endif
