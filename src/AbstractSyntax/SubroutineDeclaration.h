#ifndef OXC_SUBROUTINE_ITEM_H
#define OXC_SUBROUTINE_ITEM_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "FunctionType.h"
#include "Declaration.h"
#include "Visitor/Visitor.h"

class Node::SubroutineDeclaration: public Node, public std::enable_shared_from_this<SubroutineDeclaration> {
public:
  SubroutineDeclaration(std::string identifier, std::shared_ptr<FunctionType> function_type, std::shared_ptr<BlockStatement> block_statement);

  std::string identifier;

  std::shared_ptr<FunctionType> function_type;

  std::shared_ptr<BlockStatement> block_statement;

  void accept(Visitor &visitor) override;
};

#endif
