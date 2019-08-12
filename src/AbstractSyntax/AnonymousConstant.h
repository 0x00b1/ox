#ifndef OXC_ABSTRACT_SYNTAX_ANONYMOUS_CONSTANT_H
#define OXC_ABSTRACT_SYNTAX_ANONYMOUS_CONSTANT_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Expression.h"
#include "Node.h"

class Node::AnonymousConstant: public Node, public std::enable_shared_from_this<AnonymousConstant> {
public:
  explicit AnonymousConstant(std::shared_ptr<Node> expression);

  std::shared_ptr<Node> expression;

  void accept(Visitor &visitor) override;
};

#endif
