#ifndef OXC_ABSTRACT_SYNTAX_NAME_H
#define OXC_ABSTRACT_SYNTAX_NAME_H

#include <memory>
#include <string>
#include <utility>

#include "Visitor/Visitor.h"

class Node::Name: public Node, public std::enable_shared_from_this<Name> {
public:
  Name();

  void accept(Visitor &visitor) override;
};

#endif
