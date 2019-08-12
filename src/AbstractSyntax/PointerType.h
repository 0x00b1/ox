#ifndef OXC_ABSTRACT_SYNTAX_POINTER_TYPE_H
#define OXC_ABSTRACT_SYNTAX_POINTER_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "Type.h"
#include "ox/Visitor.h"

class Node::PointerType: public Node, public std::enable_shared_from_this<PointerType> {
public:
  PointerType();

  void accept(Visitor &visitor) override;
};

#endif
