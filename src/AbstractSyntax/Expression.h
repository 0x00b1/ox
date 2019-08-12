#ifndef OXC_ABSTRACT_SYNTAX_EXPRESSION_H
#define OXC_ABSTRACT_SYNTAX_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>

#include "Node.h"
#include "ox/Visitor.h"

class Node::Expression: public Node, public std::enable_shared_from_this<Expression> {
public:
  explicit Expression(std::shared_ptr<Node> node);

  std::shared_ptr<Node> node;

  void accept(Visitor &visitor) override;
};

#endif
