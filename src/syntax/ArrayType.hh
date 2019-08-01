#ifndef OXC_ARRAY_TYPE_HH
#define OXC_ARRAY_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::ArrayType : public Node, public std::enable_shared_from_this<ArrayType> {
public:
  ArrayType();

  void accept(Visitor &visitor) override;
};

#endif
