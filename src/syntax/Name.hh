#ifndef OXC_NAME_HH
#define OXC_NAME_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::Name: public Node, public std::enable_shared_from_this<Name> {
public:
  Name();

  void accept(Visitor &visitor) override;
};

#endif
