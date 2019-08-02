#ifndef OXC_BOTTOM_TYPE_HH
#define OXC_BOTTOM_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "Type.h"
#include "Visitor.h"

class Node::BottomType: public Type, public std::enable_shared_from_this<BottomType> {
public:
  BottomType();

  void accept(Visitor &visitor) override;
};

#endif
