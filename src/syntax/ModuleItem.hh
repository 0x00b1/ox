#ifndef OXC_MODULE_ITEM_HH
#define OXC_MODULE_ITEM_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::ModuleItem: public Item, public std::enable_shared_from_this<ModuleItem> {
public:
  ModuleItem();

  void accept(Visitor &visitor) override;
};

#endif
