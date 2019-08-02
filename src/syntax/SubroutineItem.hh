#ifndef OXC_SUBROUTINE_ITEM_HH
#define OXC_SUBROUTINE_ITEM_HH

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Visitor.hh"

class Node::SubroutineItem: public Item, public std::enable_shared_from_this<SubroutineItem> {
public:
  SubroutineItem(std::shared_ptr<FunctionDeclaration> declaration, std::shared_ptr<BlockStatement> block_statement);

  std::shared_ptr<FunctionDeclaration> declaration;

  std::shared_ptr<BlockStatement> block_statement;

  void accept(Visitor &visitor) override;
};

#endif
