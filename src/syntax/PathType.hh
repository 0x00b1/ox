#ifndef OXC_PATH_TYPE_HH
#define OXC_PATH_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::PathType: public Node::Node, public std::enable_shared_from_this<PathType> {
public:
  PathType();

  void accept(Visitor &visitor) override;
};

#endif
