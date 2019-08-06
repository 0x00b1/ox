#ifndef OXC_ABSTRACT_SYNTAX_FUNCTION_PROTOTYPE_H
#define OXC_ABSTRACT_SYNTAX_FUNCTION_PROTOTYPE_H

#include <memory>
#include <string>
#include <utility>

#include "Node.h"
#include "Visitor/Visitor.h"

class Node::FunctionPrototype: public Node, public std::enable_shared_from_this<FunctionPrototype> {
public:
  FunctionPrototype();

  void accept(Visitor &visitor) override;
};

#endif
