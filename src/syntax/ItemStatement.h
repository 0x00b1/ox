#ifndef OXC_ITEM_STATEMENT_H
#define OXC_ITEM_STATEMENT_H

#include <memory>
#include <string>
#include <utility>

#include "Statement.h"
#include "Visitor.h"

class Node::ItemStatement: public Statement, public std::enable_shared_from_this<ItemStatement> {
public:
  explicit ItemStatement(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
