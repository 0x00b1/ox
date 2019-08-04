#ifndef OXC_IDENTIFIER_H
#define OXC_IDENTIFIER_H

#include <memory>
#include <string>
#include <utility>

#include "Position.h"
#include "Visitor.h"

class Node::Identifier: public Node, public std::enable_shared_from_this<Identifier> {
public:
  explicit Identifier(std::string value);

  Position position;

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
