#ifndef OXC_ABSTRACT_SYNTAX_SLICE_PATTERN_H
#define OXC_ABSTRACT_SYNTAX_SLICE_PATTERN_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "ox/Visitor.h"

#include "Pattern.h"

class Node::SlicePattern: public Node, public std::enable_shared_from_this<SlicePattern> {
public:
  explicit SlicePattern(std::vector<std::shared_ptr<Pattern>> patterns);

  std::vector<std::shared_ptr<Pattern>> patterns;

  void accept(Visitor &visitor) override;
};

#endif
