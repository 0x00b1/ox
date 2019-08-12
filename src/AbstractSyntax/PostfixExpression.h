#ifndef OXC_ABSTRACT_SYNTAX_POSTFIX_OPERATOR_EXPRESSION_H
#define OXC_ABSTRACT_SYNTAX_POSTFIX_OPERATOR_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Node.h"

class Node::PostfixExpression: public Node, public std::enable_shared_from_this<PostfixExpression> {
public:
  explicit PostfixExpression(std::shared_ptr<Node> expression);

  std::shared_ptr<Node> expression;

  void accept(Visitor &visitor) override;
};

#endif
