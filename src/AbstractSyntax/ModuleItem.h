#ifndef OXC_MODULE_ITEM_H
#define OXC_MODULE_ITEM_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Item.h"
#include "Visitor/Visitor.h"

class Node::ModuleItem: public Node, public std::enable_shared_from_this<ModuleItem> {
public:
  explicit ModuleItem(std::string identifier);

  ModuleItem(std::string identifier, std::vector<std::shared_ptr<Item>> items);

  std::string identifier;

  std::vector<std::shared_ptr<Item>> items;

  void accept(Visitor &visitor) override;
};

#endif
