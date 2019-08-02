#ifndef OXC_BLOCK_STATEMENT_HH
#define OXC_BLOCK_STATEMENT_HH

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Statement.hh"
#include "Visitor.hh"

class Node::BlockStatement: public Statement, public std::enable_shared_from_this<BlockStatement> {
public:
  explicit BlockStatement(std::vector<std::shared_ptr<Statement>> statements);

  std::vector<std::shared_ptr<Statement>> statements;

  void accept(Visitor &visitor) override;
};

#endif
