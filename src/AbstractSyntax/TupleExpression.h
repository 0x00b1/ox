#ifndef OXC_ABSTRACT_SYNTAX_TUPLE_EXPRESSION_H
#define OXC_ABSTRACT_SYNTAX_TUPLE_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Expression.h"
#include "ox/Visitor.h"

class Node::TupleExpression: public Node, public std::enable_shared_from_this<TupleExpression> {
public:
  explicit TupleExpression(std::vector<std::shared_ptr<Node>> elements);

  std::vector<std::shared_ptr<Node>> elements;

  void accept(Visitor &visitor) override;
};

#endif
