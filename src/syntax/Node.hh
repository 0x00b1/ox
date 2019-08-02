#ifndef OXC_NODE_H
#define OXC_NODE_H

#include "Position.h"

class Visitor;

namespace Node {
  class Node {
  public:
    Position position;

    virtual void accept(Visitor &visitor) = 0;
  };
}

#endif
