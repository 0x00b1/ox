#ifndef OXC_SIZE_TYPE_H
#define OXC_SIZE_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "Type.h"
#include "Visitor.h"

class Node::SizeType: public Node, public std::enable_shared_from_this<SizeType> {
public:
  SizeType();

  void accept(Visitor &visitor) override;
};

#endif
