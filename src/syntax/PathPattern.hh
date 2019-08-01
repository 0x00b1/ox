#ifndef OXC_PATH_PATTERN_HH
#define OXC_PATH_PATTERN_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::PathPattern: public Node, public std::enable_shared_from_this<PathPattern> {
public:
  PathPattern();

  void accept(Visitor &visitor) override;
};

#endif
