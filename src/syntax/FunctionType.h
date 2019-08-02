#ifndef OXC_FUNCTION_TYPE_H
#define OXC_FUNCTION_TYPE_H

#include <memory>
#include <string>
#include <utility>

#include "Type.h"
#include "Visitor.h"

class Node::FunctionType: public Type, public std::enable_shared_from_this<FunctionType> {
public:
  FunctionType();

  void accept(Visitor &visitor) override;
};

#endif
