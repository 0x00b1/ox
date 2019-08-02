#ifndef OXC_ARRAY_TYPE_HH
#define OXC_ARRAY_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "AnonymousConstant.h"
#include "Type.h"
#include "Visitor.h"

class Node::ArrayType: public Type, public std::enable_shared_from_this<ArrayType> {
public:
  explicit ArrayType(std::shared_ptr<Type> type);

  std::shared_ptr<Type> type;

  void accept(Visitor &visitor) override;
};

#endif
