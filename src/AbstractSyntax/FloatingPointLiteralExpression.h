#ifndef OXC_ABSTRACT_SYNTAX_FLOATING_POINT_LITERAL_H
#define OXC_ABSTRACT_SYNTAX_FLOATING_POINT_LITERAL_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

class Node::FloatingPointLiteralExpression: public Node, public std::enable_shared_from_this<FloatingPointLiteralExpression> {
public:
  explicit FloatingPointLiteralExpression(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
