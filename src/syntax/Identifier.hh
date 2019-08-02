#ifndef OXC_IDENTIFIER_HH
#define OXC_IDENTIFIER_HH

#include <memory>
#include <string>
#include <utility>

#include "Position.hh"
#include "Visitor.hh"

class Node::Identifier: public Node, public std::enable_shared_from_this<Identifier> {
public:
  Identifier();

  Position position;

  void accept(Visitor &visitor) override;
};

#endif
