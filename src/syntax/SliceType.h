#ifndef OXC_SLICE_TYPE_H
#define OXC_SLICE_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "Type.h"
#include "Visitor.h"

class Node::SliceType: public Type, public std::enable_shared_from_this<SliceType> {
public:
  SliceType();

  void accept(Visitor &visitor) override;
};

#endif
