#ifndef OXC_BOOLEAN_TYPE_HH
#define OXC_BOOLEAN_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::BooleanType: public Node::Node, public std::enable_shared_from_this<BooleanType> {
public:
  BooleanType();

  void accept(Visitor &visitor) override;
};

#endif
