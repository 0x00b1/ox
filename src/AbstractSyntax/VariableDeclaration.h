#ifndef OXC_ABSTRACT_SYNTAX_VARIABLE_DECLARATION_H
#define OXC_ABSTRACT_SYNTAX_VARIABLE_DECLARATION_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

class Node::VariableDeclaration: public Node, public std::enable_shared_from_this<VariableDeclaration> {
public:
  VariableDeclaration();

  void accept(Visitor &visitor) override;
};

#endif
