#ifndef OXC_PATH_PATTERN_H
#define OXC_PATH_PATTERN_H

#include <memory>
#include <string>
#include <utility>

#include "Pattern.h"
#include "Visitor.h"

class Node::PathPattern: public Pattern, public std::enable_shared_from_this<PathPattern> {
public:
  PathPattern();

  void accept(Visitor &visitor) override;
};

#endif
