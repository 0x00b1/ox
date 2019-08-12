#ifndef OXC_ABSTRACT_SYNTAX_BOOLEAN_LITERAL_H
#define OXC_ABSTRACT_SYNTAX_BOOLEAN_LITERAL_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

class Node::BooleanLiteralExpression: public Node, public std::enable_shared_from_this<BooleanLiteralExpression> {
public:
  explicit BooleanLiteralExpression(bool value);

  bool value;

  void accept(Visitor &visitor) override;
};

#endif
