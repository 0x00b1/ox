#ifndef OXC_POINTER_TYPE_H
#define OXC_POINTER_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "Type.h"
#include "Visitor.h"

class Node::PointerType: public Type, public std::enable_shared_from_this<PointerType> {
public:
  PointerType();

  void accept(Visitor &visitor) override;
};

#endif
