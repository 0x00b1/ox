#ifndef OXC_ASSIGNMENT_STATEMENT_H
#define OXC_ASSIGNMENT_STATEMENT_H

#include <memory>
#include <string>
#include <utility>

#include "Statement.h"
#include "Visitor.h"

class Node::AssignmentStatement: public Statement, public std::enable_shared_from_this<AssignmentStatement> {
public:
  explicit AssignmentStatement(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
