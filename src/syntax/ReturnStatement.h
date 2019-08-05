#ifndef OXC_RETURN_STATEMENT_H
#define OXC_RETURN_STATEMENT_H

#include <memory>
#include <optional>
#include <string>
#include <utility>

#include "Expression.h"
#include "Statement.h"
#include "Visitor.h"

class Node::ReturnStatement: public Node, public std::enable_shared_from_this<ReturnStatement> {
public:
  explicit ReturnStatement();

  explicit ReturnStatement(std::shared_ptr<Node> expression);

  std::optional<std::shared_ptr<Node>> expression;

  void accept(Visitor &visitor) override;
};

#endif
