#ifndef OXC_SLICE_PATTERN_H
#define OXC_SLICE_PATTERN_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Pattern.h"
#include "Visitor/Visitor.h"

class Node::SlicePattern: public Node, public std::enable_shared_from_this<SlicePattern> {
public:
  explicit SlicePattern(std::vector<std::shared_ptr<Pattern>> patterns);

  std::vector<std::shared_ptr<Pattern>> patterns;

  void accept(Visitor &visitor) override;
};

#endif