#ifndef OXC_TYPE_ITEM_H
#define OXC_TYPE_ITEM_H

#include <memory>
#include <string>
#include <utility>

#include "Item.h"
#include "Type.h"
#include "Visitor.h"

class Node::TypeItem: public Node, public std::enable_shared_from_this<TypeItem> {
public:
  TypeItem(std::string identifier, std::shared_ptr<Type> type);

  std::string identifier;

  std::shared_ptr<Type> type;

  void accept(Visitor &visitor) override;
};

#endif
