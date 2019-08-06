#ifndef OXC_SUBROUTINE_ITEM_H
#define OXC_SUBROUTINE_ITEM_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "ox/Visitor.h"

#include "Declaration.h"
#include "FunctionDeclaration.h"

class Node::SubroutineDeclaration: public Node, public std::enable_shared_from_this<SubroutineDeclaration> {
public:
  SubroutineDeclaration(std::shared_ptr<FunctionDeclaration> function_declaration, std::shared_ptr<BlockStatement> block_statement);

  std::shared_ptr<FunctionDeclaration> function_declaration;

  std::shared_ptr<BlockStatement> block_statement;

  void accept(Visitor &visitor) override;
};

#endif
