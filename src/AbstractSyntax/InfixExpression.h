#ifndef OXC_ABSTRACT_SYNTAX_INFIX_OPERATOR_EXPRESSION_H
#define OXC_ABSTRACT_SYNTAX_INFIX_OPERATOR_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Expression.h"
#include "PrefixExpression.h"

class Node::InfixExpression: public Node, public std::enable_shared_from_this<InfixExpression> {
public:
  InfixExpression(std::string operation, std::shared_ptr<PrefixExpression> expression);

  std::shared_ptr<PrefixExpression> expression;

  std::string operation;

  void accept(Visitor &visitor) override;
};

#endif
