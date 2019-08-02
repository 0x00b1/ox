#ifndef OXC_PATH_TYPE_H
#define OXC_PATH_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "Type.h"
#include "Visitor.h"

class Node::PathType: public Type, public std::enable_shared_from_this<PathType> {
public:
  PathType();

  void accept(Visitor &visitor) override;
};

#endif
