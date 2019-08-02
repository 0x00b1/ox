#ifndef OXC_TUPLE_EXPRESSION_HH
#define OXC_TUPLE_EXPRESSION_HH

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Visitor.hh"

class Node::TupleExpression: public Node::Node, public std::enable_shared_from_this<TupleExpression> {
public:
  explicit TupleExpression(std::vector<std::shared_ptr<Expression>> elements);

  std::vector<std::shared_ptr<Expression>> elements;

  void accept(Visitor &visitor) override;
};

#endif
