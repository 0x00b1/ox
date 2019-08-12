#ifndef OXC_ABSTRACT_SYNTAX_TYPE_H
#define OXC_ABSTRACT_SYNTAX_TYPE_H

#include "Node.h"

#include <memory>
#include <string>
#include <utility>

#include "Node.h"
#include "Visitor/Visitor.h"

class Node::Type: public Node, public std::enable_shared_from_this<Type> {
public:
  explicit Type(std::shared_ptr<Node> node);

  std::shared_ptr<Node> node;

  void accept(Visitor &visitor) override;
};

#endif
