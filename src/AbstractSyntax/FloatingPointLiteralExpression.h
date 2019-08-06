#ifndef OXC_FLOATING_POINT_LITERAL_H
#define OXC_FLOATING_POINT_LITERAL_H

#include <memory>
#include <string>
#include <utility>

#include "Visitor/Visitor.h"

class Node::FloatingPointLiteralExpression: public Node, public std::enable_shared_from_this<FloatingPointLiteralExpression> {
public:
  explicit FloatingPointLiteralExpression(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
