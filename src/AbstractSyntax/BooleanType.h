#ifndef OXC_ABSTRACT_SYNTAX_BOOLEAN_TYPE_H
#define OXC_ABSTRACT_SYNTAX_BOOLEAN_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Type.h"

class Node::BooleanType: public Node, public std::enable_shared_from_this<BooleanType> {
public:
  BooleanType();

  void accept(Visitor &visitor) override;
};

#endif
