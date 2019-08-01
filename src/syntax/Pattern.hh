#ifndef OXC_PATTERN_HH
#define OXC_PATTERN_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::Pattern: public Node::Node, public std::enable_shared_from_this<Pattern> {
public:
  explicit Pattern(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
