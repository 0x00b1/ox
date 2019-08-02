#ifndef OXC_REFERENCE_TYPE_HH
#define OXC_REFERENCE_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "Type.h"
#include "Visitor.h"

class Node::ReferenceType: public Type, public std::enable_shared_from_this<ReferenceType> {
public:
  ReferenceType();

  void accept(Visitor &visitor) override;
};

#endif
