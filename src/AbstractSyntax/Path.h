#ifndef OXC_ABSTRACT_SYNTAX_PATH_H
#define OXC_ABSTRACT_SYNTAX_PATH_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Identifier.h"

#include "ox/Visitor.h"

class Node::Path: public Node, public std::enable_shared_from_this<Path> {
public:
  explicit Path(std::vector<std::shared_ptr<PathSegment>> path_segments);

  std::vector<std::shared_ptr<PathSegment>> path_segments;

  void accept(Visitor &visitor) override;
};

#endif
