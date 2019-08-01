#ifndef OXC_LITERAL_HH
#define OXC_LITERAL_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::Literal : public Node::Node, public std::enable_shared_from_this<Literal> {
public:
  explicit Literal(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
