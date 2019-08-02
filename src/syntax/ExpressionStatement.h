#ifndef OXC_EXPRESSION_STATEMENT_HH
#define OXC_EXPRESSION_STATEMENT_HH

#include <memory>
#include <string>
#include <utility>

#include "Statement.h"
#include "Visitor.h"

class Node::ExpressionStatement: public Statement, public std::enable_shared_from_this<ExpressionStatement> {
public:
  explicit ExpressionStatement(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
