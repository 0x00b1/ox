#ifndef OXC_STATEMENT_HH
#define OXC_STATEMENT_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::Statement: public Node, public std::enable_shared_from_this<Statement> {
public:
  explicit Statement(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif

