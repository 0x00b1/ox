#ifndef OXC_ABSTRACT_SYNTAX_IDENTIFIER_H
#define OXC_ABSTRACT_SYNTAX_IDENTIFIER_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

class Node::Identifier: public Node, public std::enable_shared_from_this<Identifier> {
public:
  explicit Identifier(std::string name);

  std::string name;

  void accept(Visitor &visitor) override;
};

#endif
