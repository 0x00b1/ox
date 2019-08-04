#ifndef OXC_EXTERNAL_PACKAGE_ITEM_H
#define OXC_EXTERNAL_PACKAGE_ITEM_H

#include <memory>
#include <string>
#include <utility>

#include "Item.h"
#include "Visitor.h"

class Node::ExternalPackageItem: public Item, public std::enable_shared_from_this<ExternalPackageItem> {
public:
  explicit ExternalPackageItem(std::string identifier);

  ExternalPackageItem(std::string identifier, std::string alias);

  std::string identifier;

  std::string alias;

  void accept(Visitor &visitor) override;
};

#endif
