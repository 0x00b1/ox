#ifndef OXC_SUBROUTINE_ITEM_H
#define OXC_SUBROUTINE_ITEM_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Item.h"
#include "Visitor.h"

class Node::SubroutineItem: public Item, public std::enable_shared_from_this<SubroutineItem> {
public:
  SubroutineItem(std::shared_ptr<FunctionDeclaration> declaration, std::shared_ptr<BlockStatement> block_statement);

  std::shared_ptr<FunctionDeclaration> declaration;

  std::shared_ptr<BlockStatement> block_statement;

  void accept(Visitor &visitor) override;
};

#endif
