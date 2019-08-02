#ifndef OXC_TUPLE_PATTERN_HH
#define OXC_TUPLE_PATTERN_HH

#include <memory>
#include <string>
#include <utility>

#include "Pattern.h"
#include "Visitor.h"

class Node::TuplePattern: public Pattern, public std::enable_shared_from_this<TuplePattern> {
public:
  TuplePattern();

  void accept(Visitor &visitor) override;
};

#endif
