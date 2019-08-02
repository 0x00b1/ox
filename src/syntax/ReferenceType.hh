#ifndef OXC_REFERENCE_TYPE_HH
#define OXC_REFERENCE_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::ReferenceType: public Node, public std::enable_shared_from_this<ReferenceType> {
public:
  ReferenceType();

  void accept(Visitor &visitor) override;
};

#endif
