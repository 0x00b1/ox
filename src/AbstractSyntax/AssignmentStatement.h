#ifndef OXC_ABSTRACT_SYNTAX_ASSIGNMENT_STATEMENT_H
#define OXC_ABSTRACT_SYNTAX_ASSIGNMENT_STATEMENT_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "PlaceExpression.h"
#include "ValueExpression.h"

class Node::AssignmentStatement: public Node, public std::enable_shared_from_this<AssignmentStatement> {
public:
  /*
   *    x ← True;
   */
  AssignmentStatement(std::shared_ptr<PlaceExpression> place_expression, std::shared_ptr<ValueExpression> value_expression);

  std::shared_ptr<PlaceExpression> place_expression;

  std::shared_ptr<ValueExpression> value_expression;

  void accept(Visitor &visitor) override;
};

#endif
