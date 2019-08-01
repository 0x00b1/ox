#ifndef OXC_BOTTOM_TYPE_HH
#define OXC_BOTTOM_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::BottomType: public Node::Node, public std::enable_shared_from_this<BottomType> {
public:
  BottomType();

  void accept(Visitor &visitor) override;
};

#endif
