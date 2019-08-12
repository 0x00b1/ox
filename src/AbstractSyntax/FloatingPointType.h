#ifndef OXC_ABSTRACT_SYNTAX_FLOATING_POINT_TYPE_H
#define OXC_ABSTRACT_SYNTAX_FLOATING_POINT_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Type.h"

class Node::FloatingPointType: public Node, public std::enable_shared_from_this<FloatingPointType> {
public:
  FloatingPointType();

  void accept(Visitor &visitor) override;
};

#endif
