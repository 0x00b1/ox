#ifndef OXC_ABSTRACT_SYNTAX_SIZE_TYPE_H
#define OXC_ABSTRACT_SYNTAX_SIZE_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Type.h"

class Node::SizeType: public Node, public std::enable_shared_from_this<SizeType> {
public:
  SizeType();

  void accept(Visitor &visitor) override;
};

#endif
