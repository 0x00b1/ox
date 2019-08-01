#ifndef OXC_CONDITIONAL_STATEMENT_HH
#define OXC_CONDITIONAL_STATEMENT_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::ConditionalStatement : public Node::Node, public std::enable_shared_from_this<ConditionalStatement> {
public:
  explicit ConditionalStatement(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
