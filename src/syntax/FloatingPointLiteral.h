#ifndef OXC_FLOATING_POINT_LITERAL_H
#define OXC_FLOATING_POINT_LITERAL_H

#include <memory>
#include <string>
#include <utility>

#include "Visitor.h"

class Node::FloatingPointLiteral: public Node, public std::enable_shared_from_this<FloatingPointLiteral> {
public:
  explicit FloatingPointLiteral(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
