#ifndef OXC_ITEM_STATEMENT_H
#define OXC_ITEM_STATEMENT_H

#include <memory>
#include <string>
#include <utility>

#include "Item.h"
#include "Statement.h"
#include "Visitor.h"

class Node::ItemStatement: public Statement, public std::enable_shared_from_this<ItemStatement> {
public:
  explicit ItemStatement(std::shared_ptr<Item> item);

  std::shared_ptr<Item> item;

  void accept(Visitor &visitor) override;
};

#endif
