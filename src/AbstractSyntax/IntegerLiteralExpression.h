#ifndef OXC_ABSTRACT_SYNTAX_INTEGER_LITERAL_H
#define OXC_ABSTRACT_SYNTAX_INTEGER_LITERAL_H

#include <memory>
#include <string>
#include <utility>

#include "Visitor/Visitor.h"

class Node::IntegerLiteralExpression: public Node, public std::enable_shared_from_this<IntegerLiteralExpression> {
public:
  explicit IntegerLiteralExpression(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
