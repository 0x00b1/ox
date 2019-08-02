#ifndef OXC_FUNCTION_DECLARATION_H
#define OXC_FUNCTION_DECLARATION_H

#include <memory>
#include <string>
#include <utility>

#include "Node.hh"
#include "Visitor.h"

class Node::FunctionDeclaration: public Node, public std::enable_shared_from_this<FunctionDeclaration> {
public:
  FunctionDeclaration();

  void accept(Visitor &visitor) override;
};

#endif
