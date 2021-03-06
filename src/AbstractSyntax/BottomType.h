#ifndef OXC_ABSTRACT_SYNTAX_BOTTOM_TYPE_H
#define OXC_ABSTRACT_SYNTAX_BOTTOM_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Type.h"

class Node::BottomType: public Node, public std::enable_shared_from_this<BottomType> {
public:
  BottomType();

  void accept(Visitor &visitor) override;
};

#endif
