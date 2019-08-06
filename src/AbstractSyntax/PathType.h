#ifndef OXC_PATH_TYPE_H
#define OXC_PATH_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "Type.h"
#include "Visitor/Visitor.h"

class Node::PathType: public Node, public std::enable_shared_from_this<PathType> {
public:
  explicit PathType(std::shared_ptr<Path> path);

  std::shared_ptr<Path> path;

  void accept(Visitor &visitor) override;
};

#endif
