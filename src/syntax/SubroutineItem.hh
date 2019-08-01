#ifndef OXC_SUBROUTINE_ITEM_HH
#define OXC_SUBROUTINE_ITEM_HH

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Argument.hh"
#include "BlockStatement.hh"
#include "Type.hh"

class Node::SubroutineItem: public Node::Node, public std::enable_shared_from_this<SubroutineItem> {
public:
  SubroutineItem( std::vector<Argument> arguments, std::shared_ptr<Type> type, std::shared_ptr<BlockStatement> block_statement);

  std::vector<Argument> arguments;

  std::shared_ptr<Type> type;

  std::shared_ptr<BlockStatement> block_statement;

  void accept(Visitor &visitor) override;
};

#endif

