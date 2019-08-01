#ifndef OXC_INTEGER_LITERAL_HH
#define OXC_INTEGER_LITERAL_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::IntegerLiteral: public Node::Node, public std::enable_shared_from_this<IntegerLiteral> {
public:
  explicit IntegerLiteral(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
