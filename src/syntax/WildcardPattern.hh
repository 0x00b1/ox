#ifndef OXC_WILDCARD_PATTERN_HH
#define OXC_WILDCARD_PATTERN_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::WildcardPattern: public Node, public std::enable_shared_from_this<WildcardPattern> {
public:
  WildcardPattern();

  void accept(Visitor &visitor) override;
};

#endif