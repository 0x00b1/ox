#ifndef OXC_PREFIX_OPERATION_H
#define OXC_PREFIX_OPERATION_H

#include <memory>
#include <string>
#include <utility>

#include "Pattern.h"
#include "Visitor/Visitor.h"

class Node::PrefixOperation: public Node, public std::enable_shared_from_this<PrefixOperation> {
public:
  explicit PrefixOperation();

  void accept(Visitor &visitor) override;
};

#endif
