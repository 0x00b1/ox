#ifndef OXC_ARRAY_TYPE_HH
#define OXC_ARRAY_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "AnonymousConstant.hh"
#include "Type.hh"
#include "Visitor.hh"

class Node::ArrayType: public Type, public std::enable_shared_from_this<ArrayType> {
public:
  ArrayType(std::shared_ptr<Type> type, AnonymousConstant size);

  std::shared_ptr<Type> type;

  void accept(Visitor &visitor) override;
};

#endif
