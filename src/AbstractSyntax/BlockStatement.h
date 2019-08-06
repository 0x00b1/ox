#ifndef OXC_BLOCK_STATEMENT_H
#define OXC_BLOCK_STATEMENT_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Statement.h"
#include "Visitor/Visitor.h"

class Node::BlockStatement: public Node, public std::enable_shared_from_this<BlockStatement> {
public:
  explicit BlockStatement(std::vector<std::shared_ptr<Statement>> statements);

  std::vector<std::shared_ptr<Statement>> statements;

  void accept(Visitor &visitor) override;
};

#endif
