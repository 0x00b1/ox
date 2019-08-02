#ifndef OXC_EXTERNAL_PACKAGE_ITEM_H
#define OXC_EXTERNAL_PACKAGE_ITEM_H

#include <memory>
#include <string>
#include <utility>

#include "Item.h"
#include "Visitor.h"

class Node::ExternalPackageItem: public Item, public std::enable_shared_from_this<ExternalPackageItem> {
public:
  ExternalPackageItem();

  void accept(Visitor &visitor) override;
};

#endif
