#ifndef OXC_REFERENCE_TYPE_H
#define OXC_REFERENCE_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "Type.h"
#include "Visitor.h"

class Node::ReferenceType: public Node, public std::enable_shared_from_this<ReferenceType> {
public:
  explicit ReferenceType(std::shared_ptr<Type> type);

  std::shared_ptr<Type> type;

  void accept(Visitor &visitor) override;
};

#endif
