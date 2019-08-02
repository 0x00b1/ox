#ifndef OXC_FLOATING_POINT_TYPE_HH
#define OXC_FLOATING_POINT_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::FloatingPointType: public Type, public std::enable_shared_from_this<FloatingPointType> {
public:
  FloatingPointType();

  void accept(Visitor &visitor) override;
};

#endif
