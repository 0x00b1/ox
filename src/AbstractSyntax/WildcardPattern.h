#ifndef OXC_ABSTRACT_SYNTAX_WILDCARD_PATTERN_H
#define OXC_ABSTRACT_SYNTAX_WILDCARD_PATTERN_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Pattern.h"

class Node::WildcardPattern: public Node, public std::enable_shared_from_this<WildcardPattern> {
public:
  WildcardPattern();

  void accept(Visitor &visitor) override;
};

#endif
