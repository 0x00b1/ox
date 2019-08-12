#ifndef OXC_ABSTRACT_SYNTAX_PATH_EXPRESSION_H
#define OXC_ABSTRACT_SYNTAX_PATH_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Expression.h"
#include "ox/Visitor.h"

class Node::PathExpression: public Node, public std::enable_shared_from_this<PathExpression> {
public:
  explicit PathExpression(std::string identifier);

  std::string identifier;

  void accept(Visitor &visitor) override;
};

#endif
