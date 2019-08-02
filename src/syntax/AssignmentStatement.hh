#ifndef OXC_ASSIGNMENT_STATEMENT_HH
#define OXC_ASSIGNMENT_STATEMENT_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::AssignmentStatement: public Statement, public std::enable_shared_from_this<AssignmentStatement> {
public:
  explicit AssignmentStatement(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
