#ifndef OXC_ABSTRACT_SYNTAX_PATTERN_H
#define OXC_ABSTRACT_SYNTAX_PATTERN_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Node.h"

class Node::Pattern: public Node, public std::enable_shared_from_this<Pattern> {
public:
  explicit Pattern(std::shared_ptr<Node> node);

  std::shared_ptr<Node> node;

  void accept(Visitor &visitor) override;
};

#endif
