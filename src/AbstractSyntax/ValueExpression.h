#ifndef OXC_ABSTRACT_SYNTAX_VALUE_EXPRESSION_H
#define OXC_ABSTRACT_SYNTAX_VALUE_EXPRESSION_H

#include "Node.h"

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Node.h"

class Node::ValueExpression: public Node, public std::enable_shared_from_this<ValueExpression> {
public:
  explicit ValueExpression(std::shared_ptr<Node> node);

  std::shared_ptr<Node> node;

  void accept(Visitor &visitor) override;
};

#endif
