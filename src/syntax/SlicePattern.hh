#ifndef OXC_SLICE_PATTERN_HH
#define OXC_SLICE_PATTERN_HH

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Pattern.hh"
#include "Visitor.hh"

class Node::SlicePattern: public Pattern, public std::enable_shared_from_this<SlicePattern> {
public:
  explicit SlicePattern(std::vector<std::shared_ptr<Pattern>> patterns);

  std::vector<std::shared_ptr<Pattern>> patterns;

  void accept(Visitor &visitor) override;
};

#endif
