#ifndef OXC_TYPE_HH
#define OXC_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::Type: public Node::Node, public std::enable_shared_from_this<Type> {
public:
  explicit Type(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
