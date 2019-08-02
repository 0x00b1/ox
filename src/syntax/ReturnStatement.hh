#ifndef OXC_RETURN_STATEMENT_HH
#define OXC_RETURN_STATEMENT_HH

#include <memory>
#include <optional>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::ReturnStatement: public Node, public std::enable_shared_from_this<ReturnStatement> {
public:
  explicit ReturnStatement();

  explicit ReturnStatement(std::shared_ptr<Expression> expression);

  std::optional<std::shared_ptr<Expression>> expression;

  void accept(Visitor &visitor) override;
};

#endif
