#ifndef OXC_ABSTRACT_SYNTAX_PATH_H
#define OXC_ABSTRACT_SYNTAX_PATH_H

#include <memory>
#include <string>
#include <utility>

#include "Identifier.h"

#include "ox/Visitor.h"

class Node::Path: public Node, public std::enable_shared_from_this<Path> {
public:
  Path();

  void accept(Visitor &visitor) override;
};

#endif
