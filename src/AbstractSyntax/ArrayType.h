#ifndef OXC_ABSTRACT_SYNTAX_ARRAY_TYPE_H
#define OXC_ABSTRACT_SYNTAX_ARRAY_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "AnonymousConstant.h"
#include "Type.h"

class Node::ArrayType: public Node, public std::enable_shared_from_this<ArrayType> {
public:
  ArrayType(std::shared_ptr<Type> type, std::shared_ptr<AnonymousConstant> anonymous_constant);

  std::shared_ptr<Type> type;

  std::shared_ptr<AnonymousConstant> anonymous_constant;

  void accept(Visitor &visitor) override;
};

#endif
