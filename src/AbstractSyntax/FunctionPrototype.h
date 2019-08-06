#ifndef OXC_ABSTRACT_SYNTAX_FUNCTION_PROTOTYPE_H
#define OXC_ABSTRACT_SYNTAX_FUNCTION_PROTOTYPE_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "ox/Visitor.h"

#include "Node.h"

class Node::FunctionPrototype: public Node, public std::enable_shared_from_this<FunctionPrototype> {
public:
  FunctionPrototype(std::vector<std::shared_ptr<Parameter>> parameters, std::shared_ptr<Type> return_type);

  std::vector<std::shared_ptr<Parameter>> parameters;

  std::shared_ptr<Type> return_type;

  void accept(Visitor &visitor) override;
};

#endif
