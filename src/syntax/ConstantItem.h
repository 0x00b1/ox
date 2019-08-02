#ifndef OXC_CONSTANT_ITEM_H
#define OXC_CONSTANT_ITEM_H

#include <memory>
#include <string>
#include <utility>

#include "Item.h"
#include "Visitor.h"

class Node::ConstantItem: public Item, public std::enable_shared_from_this<ConstantItem> {
public:
  explicit ConstantItem(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
