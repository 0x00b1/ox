#ifndef OXC_ITEM_STATEMENT_HH
#define OXC_ITEM_STATEMENT_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::ItemStatement: public Statement, public std::enable_shared_from_this<ItemStatement> {
public:
  explicit ItemStatement(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
