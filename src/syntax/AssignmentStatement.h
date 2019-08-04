#ifndef OXC_ASSIGNMENT_STATEMENT_H
#define OXC_ASSIGNMENT_STATEMENT_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "Pattern.h"
#include "Statement.h"
#include "Type.h"
#include "Visitor.h"

class Node::AssignmentStatement: public Statement, public std::enable_shared_from_this<AssignmentStatement> {
public:
  AssignmentStatement(std::shared_ptr<Pattern> pattern, std::shared_ptr<Type> type, std::shared_ptr<Expression> expression);

  std::shared_ptr<Pattern> pattern;

  std::shared_ptr<Type> type;

  std::shared_ptr<Expression> expression;

  void accept(Visitor &visitor) override;
};

#endif