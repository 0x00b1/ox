#ifndef OXC_REFERENCE_PATTERN_H
#define OXC_REFERENCE_PATTERN_H

#include <memory>
#include <string>
#include <utility>

#include "Pattern.h"
#include "Visitor.h"

class Node::ReferencePattern: public Pattern, public std::enable_shared_from_this<ReferencePattern> {
public:
  explicit ReferencePattern(std::shared_ptr<Pattern> type);

  std::shared_ptr<Pattern> pattern;

  void accept(Visitor &visitor) override;
};

#endif
