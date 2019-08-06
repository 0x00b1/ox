#ifndef OXC_FUNCTION_TYPE_H
#define OXC_FUNCTION_TYPE_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Parameter.h"
#include "Type.h"
#include "Visitor/Visitor.h"

class Node::FunctionType: public Node, public std::enable_shared_from_this<FunctionType> {
public:
  FunctionType(std::vector<std::shared_ptr<Parameter>> parameters, std::shared_ptr<Type> return_type);

  std::vector<std::shared_ptr<Parameter>> parameters;

  std::shared_ptr<Type> return_type;

  void accept(Visitor &visitor) override;
};

#endif
