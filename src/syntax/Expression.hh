#ifndef OXC_EXPRESSION_STATEMENT_HH
#define OXC_EXPRESSION_STATEMENT_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::Expression: public Node::Node, public std::enable_shared_from_this<Expression> {
public:
  Expression();

  void accept(Visitor &visitor) override;
};

#endif
