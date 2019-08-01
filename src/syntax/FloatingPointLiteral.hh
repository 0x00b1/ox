#ifndef OXC_FLOATING_POINT_LITERAL_HH
#define OXC_FLOATING_POINT_LITERAL_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::FloatingPointLiteral : public Node::Node, public std::enable_shared_from_this<FloatingPointLiteral> {
public:
  FloatingPointLiteral();

  void accept(Visitor &visitor) override;
};

#endif
