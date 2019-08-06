#ifndef OXC_DECLARATION_H
#define OXC_DECLARATION_H

#include <memory>
#include <string>
#include <utility>

#include "Node.h"
#include "Visitor/Visitor.h"

class Node::Declaration: public Node, public std::enable_shared_from_this<Declaration> {
public:
  explicit Declaration(std::shared_ptr<Node> node);

  std::shared_ptr<Node> node;

  void accept(Visitor &visitor) override;
};

#endif
