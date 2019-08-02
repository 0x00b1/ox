#ifndef OXC_EXTERNAL_PACKAGE_ITEM_HH
#define OXC_EXTERNAL_PACKAGE_ITEM_HH

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
