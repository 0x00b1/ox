#ifndef OXC_TYPE_ITEM_H
#define OXC_TYPE_ITEM_H

#include <memory>
#include <string>
#include <utility>

#include "Item.h"
#include "Visitor.h"

class Node::TypeItem: public Item, public std::enable_shared_from_this<TypeItem> {
public:
  TypeItem();

  void accept(Visitor &visitor) override;
};

#endif