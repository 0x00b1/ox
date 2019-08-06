#ifndef OXC_ABSTRACT_SYNTAX_PATH_PATTERN_H
#define OXC_ABSTRACT_SYNTAX_PATH_PATTERN_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Pattern.h"

class Node::PathPattern: public Node, public std::enable_shared_from_this<PathPattern> {
public:
  explicit PathPattern(std::shared_ptr<Path> path);

  std::shared_ptr<Path> path;

  void accept(Visitor &visitor) override;
};

#endif
