#ifndef OXC_ABSTRACT_SYNTAX_LITERAL_H
#define OXC_ABSTRACT_SYNTAX_LITERAL_H

#include <memory>
#include <string>
#include <utility>

#include "Visitor/Visitor.h"

class Node::Literal: public Node, public std::enable_shared_from_this<Literal> {
public:
  explicit Literal(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
