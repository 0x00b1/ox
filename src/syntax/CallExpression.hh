#ifndef OXC_CALL_EXPRESSION_HH
#define OXC_CALL_EXPRESSION_HH

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Visitor.hh"

class Node::CallExpression : public Node::Node, public std::enable_shared_from_this<CallExpression> {
public:
  CallExpression(
      std::shared_ptr<Expression> subroutine,
      std::vector<std::shared_ptr<Expression>> parameters
  );

  std::shared_ptr<Expression> subroutine;

  std::vector<std::shared_ptr<Expression>> parameters;

  void accept(Visitor &visitor) override;
};

#endif
