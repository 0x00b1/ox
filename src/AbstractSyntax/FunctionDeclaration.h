#ifndef OXC_ABSTRACT_SYNTAX_FUNCTION_DECLARATION_H
#define OXC_ABSTRACT_SYNTAX_FUNCTION_DECLARATION_H

#include <memory>
#include <string>
#include <utility>

#include "Node.h"
#include "ox/Visitor.h"

class Node::FunctionDeclaration: public Node, public std::enable_shared_from_this<FunctionDeclaration> {
public:
  explicit FunctionDeclaration(std::shared_ptr<FunctionPrototype> function_prototype);

  std::shared_ptr<FunctionPrototype> function_prototype;

  void accept(Visitor &visitor) override;
};

#endif
