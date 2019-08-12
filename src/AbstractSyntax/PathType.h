#ifndef OXC_ABSTRACT_SYNTAX_PATH_TYPE_H
#define OXC_ABSTRACT_SYNTAX_PATH_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Type.h"

class Node::PathType: public Node, public std::enable_shared_from_this<PathType> {
public:
  explicit PathType(std::shared_ptr<Path> path);

  std::shared_ptr<Path> path;

  void accept(Visitor &visitor) override;
};

#endif
