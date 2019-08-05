#ifndef OXC_STATEMENT_H
#define OXC_STATEMENT_H

#include "Node.h"

namespace Node {
  class Statement: public Node {
  public:
    void accept(Visitor &visitor) override = 0;
  };
}

#endif
