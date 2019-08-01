#ifndef OXC_IDENTIFIER_HH
#define OXC_IDENTIFIER_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"


class Node::Identifier: public Node::Node, public std::enable_shared_from_this<Identifier> {
public:
  explicit Identifier(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
