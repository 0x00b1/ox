#ifndef OXC_SLICE_TYPE_HH
#define OXC_SLICE_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::SliceType: public Node, public std::enable_shared_from_this<SliceType> {
public:
  SliceType();

  void accept(Visitor &visitor) override;
};

#endif
