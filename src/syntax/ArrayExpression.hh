#ifndef OXC_ARRAY_EXPRESSION_HH
#define OXC_ARRAY_EXPRESSION_HH

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Visitor.hh"

class Node::ArrayExpression : public Node::Node, public std::enable_shared_from_this<ArrayExpression> {
public:
  explicit ArrayExpression(
      std::vector<std::shared_ptr<Expression>> elements
  );

  std::vector<std::shared_ptr<Expression>> elements;

  void accept(Visitor &visitor) override;
};

#endif
