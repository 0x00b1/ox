#ifndef OXC_FUNCTION_TYPE_H
#define OXC_FUNCTION_TYPE_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "ox/Visitor.h"

#include "Parameter.h"
#include "Type.h"

class Node::FunctionType: public Node, public std::enable_shared_from_this<FunctionType> {
public:
  explicit FunctionType(std::shared_ptr<FunctionDeclaration> function_declaration);

  std::shared_ptr<FunctionDeclaration> function_declaration;

  void accept(Visitor &visitor) override;
};

#endif
