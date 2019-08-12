#ifndef OXC_ABSTRACT_SYNTAX_ITEM_STATEMENT_H
#define OXC_ABSTRACT_SYNTAX_ITEM_STATEMENT_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Declaration.h"
#include "Statement.h"

class Node::DeclarationStatement: public Node, public std::enable_shared_from_this<DeclarationStatement> {
public:
  explicit DeclarationStatement(std::shared_ptr<Declaration> item);

  std::shared_ptr<Declaration> item;

  void accept(Visitor &visitor) override;
};

#endif
