#ifndef OXC_RETURN_STATEMENT_HH
#define OXC_RETURN_STATEMENT_HH

#include <memory>
#include <optional>
#include <string>
#include <utility>

#include "Expression.hh"
#include "Statement.hh"
#include "Visitor.hh"

class Node::ReturnStatement: public Statement, public std::enable_shared_from_this<ReturnStatement> {
public:
  explicit ReturnStatement();

  explicit ReturnStatement(std::shared_ptr<Expression> expression);

  std::optional<std::shared_ptr<Expression>> expression;

  void accept(Visitor &visitor) override;
};

#endif
