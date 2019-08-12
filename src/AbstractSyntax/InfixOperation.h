#ifndef OXC_ABSTRACT_SYNTAX_INFIX_OPERATION_H
#define OXC_ABSTRACT_SYNTAX_INFIX_OPERATION_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Pattern.h"

class Node::InfixOperation: public Node, public std::enable_shared_from_this<InfixOperation> {
public:
  explicit InfixOperation();

  void accept(Visitor &visitor) override;
};

#endif
