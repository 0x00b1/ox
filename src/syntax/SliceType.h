#ifndef OXC_SLICE_TYPE_H
#define OXC_SLICE_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "Type.h"
#include "Visitor.h"

class Node::SliceType: public Node, public std::enable_shared_from_this<SliceType> {
public:
  explicit SliceType(std::shared_ptr<Type> type);

  std::shared_ptr<Type> type;

  void accept(Visitor &visitor) override;
};

#endif
