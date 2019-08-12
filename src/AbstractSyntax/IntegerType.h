#ifndef OXC_ABSTRACT_SYNTAX_INTEGER_TYPE_H
#define OXC_ABSTRACT_SYNTAX_INTEGER_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Type.h"

class Node::IntegerType: public Node, public std::enable_shared_from_this<IntegerType> {
public:
  IntegerType();

  void accept(Visitor &visitor) override;
};

#endif
