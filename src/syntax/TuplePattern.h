#ifndef OXC_TUPLE_PATTERN_H
#define OXC_TUPLE_PATTERN_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Pattern.h"
#include "Visitor.h"

class Node::TuplePattern: public Pattern, public std::enable_shared_from_this<TuplePattern> {
public:
  explicit TuplePattern(std::vector<std::shared_ptr<Pattern>> patterns);

  std::vector<std::shared_ptr<Pattern>> patterns;

  void accept(Visitor &visitor) override;
};

#endif
