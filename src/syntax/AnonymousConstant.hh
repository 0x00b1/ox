#ifndef OXC_ANONYMOUS_CONSTANT_HH
#define OXC_ANONYMOUS_CONSTANT_HH

#include <memory>
#include <string>
#include <utility>

#include "Expression.hh"
#include "Node.hh"
#include "Visitor.hh"

class Node::AnonymousConstant: public Node, public std::enable_shared_from_this<AnonymousConstant> {
public:
  explicit AnonymousConstant(std::shared_ptr<Expression> expression);

  std::shared_ptr<Expression> expression;

  void accept(Visitor &visitor) override;
};

#endif
