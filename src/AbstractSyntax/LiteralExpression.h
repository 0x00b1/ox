#ifndef OXC_ABSTRACT_SYNTAX_LITERAL_EXPRESSION_H
#define OXC_ABSTRACT_SYNTAX_LITERAL_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "Visitor/Visitor.h"

class Node::LiteralExpression: public Node, public std::enable_shared_from_this<LiteralExpression> {
public:
  explicit LiteralExpression(std::shared_ptr<Node> node);

  std::shared_ptr<Node> node;

  void accept(Visitor &visitor) override;
};

#endif
