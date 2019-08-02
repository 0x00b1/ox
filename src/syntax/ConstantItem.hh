#ifndef OXC_CONSTANT_ITEM_HH
#define OXC_CONSTANT_ITEM_HH

#include <memory>
#include <string>
#include <utility>

#include "Item.hh"
#include "Visitor.hh"

class Node::ConstantItem: public Item, public std::enable_shared_from_this<ConstantItem> {
public:
  explicit ConstantItem(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
