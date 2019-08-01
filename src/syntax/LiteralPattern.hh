#ifndef OXC_LITERAL_PATTERN_HH
#define OXC_LITERAL_PATTERN_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::LiteralPattern: public Node, public std::enable_shared_from_this<Expression> {
public:
  explicit LiteralPattern(std::shared_ptr<Expression> expression);

  std::shared_ptr<Expression> expression;

  void accept(Visitor &visitor) override;
};

#endif