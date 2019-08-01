#ifndef OXC_CONSTANT_ITEM_HH
#define OXC_CONSTANT_ITEM_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::ConstantItem: public Node::Node, public std::enable_shared_from_this<ConstantItem> {
public:
  explicit ConstantItem(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
