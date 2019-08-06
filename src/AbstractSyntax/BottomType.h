#ifndef OXC_BOTTOM_TYPE_H
#define OXC_BOTTOM_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "Type.h"
#include "Visitor/Visitor.h"

class Node::BottomType: public Node, public std::enable_shared_from_this<BottomType> {
public:
  BottomType();

  void accept(Visitor &visitor) override;
};

#endif
