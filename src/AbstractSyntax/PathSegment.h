#ifndef OXC_ABSTRACT_SYNTAX_PATH_SEGMENT_H
#define OXC_ABSTRACT_SYNTAX_PATH_SEGMENT_H

#include <memory>
#include <string>
#include <utility>

#include "Identifier.h"

#include "ox/Visitor.h"

class Node::PathSegment: public Node, public std::enable_shared_from_this<PathSegment> {
public:
  explicit PathSegment(std::shared_ptr<Identifier> identifier);

  std::shared_ptr<Identifier> identifier;

  void accept(Visitor &visitor) override;
};

#endif
