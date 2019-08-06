#ifndef OXC_WILDCARD_PATTERN_H
#define OXC_WILDCARD_PATTERN_H

#include <memory>
#include <string>
#include <utility>

#include "Pattern.h"
#include "Visitor.h"

class Node::WildcardPattern: public Node, public std::enable_shared_from_this<WildcardPattern> {
public:
  WildcardPattern();

  void accept(Visitor &visitor) override;
};

#endif
