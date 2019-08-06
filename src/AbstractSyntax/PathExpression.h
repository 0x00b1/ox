#ifndef OXC_PATH_EXPRESSION_H
#define OXC_PATH_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Expression.h"
#include "Visitor/Visitor.h"

class Node::PathExpression: public Node, public std::enable_shared_from_this<PathExpression> {
public:
  explicit PathExpression(std::string identifier);

  std::string identifier;

  void accept(Visitor &visitor) override;
};

#endif
