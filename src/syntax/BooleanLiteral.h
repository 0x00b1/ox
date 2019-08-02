#ifndef OXC_BOOLEAN_LITERAL_H
#define OXC_BOOLEAN_LITERAL_H

#include <memory>
#include <string>
#include <utility>

#include "Visitor.h"

class Node::BooleanLiteral: public Node, public std::enable_shared_from_this<BooleanLiteral> {
public:
  explicit BooleanLiteral(bool value);

  bool value;

  void accept(Visitor &visitor) override;
};

#endif
