#ifndef OXC_ABSTRACT_SYNTAX_ASSIGNMENT_STATEMENT_H
#define OXC_ABSTRACT_SYNTAX_ASSIGNMENT_STATEMENT_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Expression.h"
#include "Pattern.h"
#include "Statement.h"
#include "Type.h"

class Node::AssignmentStatement: public Node, public std::enable_shared_from_this<AssignmentStatement> {
public:
  AssignmentStatement(std::shared_ptr<Pattern> pattern, std::shared_ptr<Type> type, std::shared_ptr<Node> expression);

  std::shared_ptr<Pattern> pattern;

  std::shared_ptr<Type> type;

  std::shared_ptr<Node> expression;

  void accept(Visitor &visitor) override;
};

#endif
