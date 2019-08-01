#ifndef OXC_NAME_HH
#define OXC_NAME_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::Name: public Node::Node, public std::enable_shared_from_this<Name> {
public:
  explicit Name(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
