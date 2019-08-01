#ifndef OXC_BOOLEAN_LITERAL_HH
#define OXC_BOOLEAN_LITERAL_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::BooleanLiteral: public Node::Node, public std::enable_shared_from_this<BooleanLiteral> {
public:
  BooleanLiteral();

  void accept(Visitor &visitor) override;
};

#endif
