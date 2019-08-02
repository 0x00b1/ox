#ifndef OXC_INTEGER_LITERAL_H
#define OXC_INTEGER_LITERAL_H

#include <memory>
#include <string>
#include <utility>

#include "Visitor.h"

class Node::IntegerLiteral: public Node, public std::enable_shared_from_this<IntegerLiteral> {
public:
  explicit IntegerLiteral(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
