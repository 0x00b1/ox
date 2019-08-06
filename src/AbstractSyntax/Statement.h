#ifndef OXC_STATEMENT_H
#define OXC_STATEMENT_H

#include <memory>
#include <string>
#include <utility>

#include "Node.h"
#include "Visitor/Visitor.h"

class Node::Statement: public Node, public std::enable_shared_from_this<Statement> {
public:
  explicit Statement(std::shared_ptr<Node> node);

  std::shared_ptr<Node> node;

  void accept(Visitor &visitor) override;
};

#endif
