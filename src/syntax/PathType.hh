#ifndef OXC_PATH_TYPE_HH
#define OXC_PATH_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "Type.hh"
#include "Visitor.hh"

class Node::PathType: public Type, public std::enable_shared_from_this<PathType> {
public:
  PathType();

  void accept(Visitor &visitor) override;
};

#endif
