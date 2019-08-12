#ifndef OXC_ABSTRACT_SYNTAX_BLOCK_STATEMENT_H
#define OXC_ABSTRACT_SYNTAX_BLOCK_STATEMENT_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "ox/Visitor.h"

#include "Statement.h"

class Node::BlockStatement: public Node, public std::enable_shared_from_this<BlockStatement> {
public:
  explicit BlockStatement(std::vector<std::shared_ptr<Statement>> statements);

  std::vector<std::shared_ptr<Statement>> statements;

  void accept(Visitor &visitor) override;
};

#endif
