#ifndef OXC_BOOLEAN_TYPE_H
#define OXC_BOOLEAN_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "Type.h"
#include "Visitor/Visitor.h"

class Node::BooleanType: public Node, public std::enable_shared_from_this<BooleanType> {
public:
  BooleanType();

  void accept(Visitor &visitor) override;
};

#endif