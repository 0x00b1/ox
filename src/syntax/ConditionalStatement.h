#ifndef OXC_CONDITIONAL_STATEMENT_H
#define OXC_CONDITIONAL_STATEMENT_H

#include <memory>
#include <optional>
#include <string>
#include <utility>

#include "Expression.h"
#include "Statement.h"
#include "Visitor.h"

class Node::ConditionalStatement: public Node, public std::enable_shared_from_this<ConditionalStatement> {
public:
  ConditionalStatement(std::shared_ptr<Node> predicate, std::shared_ptr<BlockStatement> consequent);

  ConditionalStatement(std::shared_ptr<Node> predicate, std::shared_ptr<BlockStatement> consequent, std::optional<std::shared_ptr<BlockStatement>> alternate);

  std::shared_ptr<Node> predicate;

  std::shared_ptr<BlockStatement> consequent;

  std::optional<std::shared_ptr<BlockStatement>> alternate;

  void accept(Visitor &visitor) override;
};

#endif
