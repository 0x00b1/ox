#ifndef OXC_BLOCK_STATEMENT_HH
#define OXC_BLOCK_STATEMENT_HH

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Visitor.hh"

class Node::BlockStatement: public Node, public std::enable_shared_from_this<BlockStatement> {
public:
  explicit BlockStatement(std::vector<Statement> statements);

  std::vector<Statement> statements;

  void accept(Visitor &visitor) override;
};

#endif
