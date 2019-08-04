#ifndef OXC_ARRAY_TYPE_H
#define OXC_ARRAY_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "AnonymousConstant.h"
#include "Type.h"
#include "Visitor.h"

class Node::ArrayType: public Type, public std::enable_shared_from_this<ArrayType> {
public:
  ArrayType(std::shared_ptr<Type> type, std::shared_ptr<AnonymousConstant> anonymous_constant);

  std::shared_ptr<Type> type;

  std::shared_ptr<AnonymousConstant> anonymous_constant;

  void accept(Visitor &visitor) override;
};

#endif
