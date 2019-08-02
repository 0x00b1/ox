#ifndef OXC_LITERAL_EXPRESSION_HH
#define OXC_LITERAL_EXPRESSION_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::LiteralExpression: public Node, public std::enable_shared_from_this<LiteralExpression> {
public:
  explicit LiteralExpression(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
