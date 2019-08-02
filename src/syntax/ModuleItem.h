#ifndef OXC_MODULE_ITEM_H
#define OXC_MODULE_ITEM_H

#include <memory>
#include <string>
#include <utility>

#include "Item.h"
#include "Visitor.h"

class Node::ModuleItem: public Item, public std::enable_shared_from_this<ModuleItem> {
public:
  ModuleItem();

  void accept(Visitor &visitor) override;
};

#endif
