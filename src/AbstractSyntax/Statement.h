#ifndef OXC_ABSTRACT_SYNTAX_STATEMENT_H
#define OXC_ABSTRACT_SYNTAX_STATEMENT_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Node.h"

class Node::Statement: public Node, public std::enable_shared_from_this<Statement> {
public:
  explicit Statement(std::shared_ptr<Node> node);

  std::shared_ptr<Node> node;

  void accept(Visitor &visitor) override;
};

#endif
