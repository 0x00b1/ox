#ifndef OXC_POINTER_TYPE_HH
#define OXC_POINTER_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::PointerType: public Type, public std::enable_shared_from_this<PointerType> {
public:
  PointerType();

  void accept(Visitor &visitor) override;
};

#endif
