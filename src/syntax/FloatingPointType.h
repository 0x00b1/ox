#ifndef OXC_FLOATING_POINT_TYPE_H
#define OXC_FLOATING_POINT_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "Type.h"
#include "Visitor.h"

class Node::FloatingPointType: public Node, public std::enable_shared_from_this<FloatingPointType> {
public:
  FloatingPointType();

  void accept(Visitor &visitor) override;
};

#endif
