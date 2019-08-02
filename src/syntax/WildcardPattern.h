#ifndef OXC_WILDCARD_PATTERN_HH
#define OXC_WILDCARD_PATTERN_HH

#include <memory>
#include <string>
#include <utility>

#include "Pattern.h"
#include "Visitor.h"

class Node::WildcardPattern: public Pattern, public std::enable_shared_from_this<WildcardPattern> {
public:
  WildcardPattern();

  void accept(Visitor &visitor) override;
};

#endif
