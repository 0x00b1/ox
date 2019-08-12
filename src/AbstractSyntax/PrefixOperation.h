#ifndef OXC_ABSTRACT_SYNTAX_PREFIX_OPERATION_H
#define OXC_ABSTRACT_SYNTAX_PREFIX_OPERATION_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Pattern.h"

class Node::PrefixOperation: public Node, public std::enable_shared_from_this<PrefixOperation> {
public:
  explicit PrefixOperation();

  void accept(Visitor &visitor) override;
};

#endif
