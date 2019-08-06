#ifndef OXC_SYNTAX_UNIT_H
#define OXC_SYNTAX_UNIT_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Node.h"
#include "Statement.h"
#include "Visitor/Visitor.h"

class Node::Unit: public Node, public std::enable_shared_from_this<Unit> {
public:
  explicit Unit(std::vector<std::shared_ptr<Statement>> statements);

  std::vector<std::shared_ptr<Statement>> statements;

  void accept(Visitor &visitor) override;
};

#endif
