#ifndef OXC_CONDITIONAL_STATEMENT_HH
#define OXC_CONDITIONAL_STATEMENT_HH

#include <memory>
#include <optional>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::ConditionalStatement: public Node::Node, public std::enable_shared_from_this<ConditionalStatement> {
public:
  ConditionalStatement(std::shared_ptr<Expression> predicate, std::shared_ptr<BlockStatement> consequent);

  ConditionalStatement(std::shared_ptr<Expression> predicate, std::shared_ptr<BlockStatement> consequent, std::optional<std::shared_ptr<BlockStatement>> alternate);

  std::shared_ptr<Expression> predicate;

  std::shared_ptr<BlockStatement> consequent;

  std::optional<std::shared_ptr<BlockStatement>> alternate;

  void accept(Visitor &visitor) override;
};

#endif
