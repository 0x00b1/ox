#ifndef OXC_NODE_HH
#define OXC_NODE_HH

#include "Position.hh"

class Visitor;

namespace Node {
  class Node {
  public:
    Position position;

    virtual void accept(Visitor &visitor) = 0;
  };
}

#endif
