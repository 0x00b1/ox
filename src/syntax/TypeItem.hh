#ifndef OXC_TYPE_ITEM_HH
#define OXC_TYPE_ITEM_HH

#include <memory>
#include <string>
#include <utility>

#include "Item.hh"
#include "Visitor.hh"

class Node::TypeItem: public Item, public std::enable_shared_from_this<TypeItem> {
public:
  TypeItem();

  void accept(Visitor &visitor) override;
};

#endif
