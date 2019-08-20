#ifndef OXC_ABSTRACT_SYNTAX_VARIABLE_DECLARATION_H
#define OXC_ABSTRACT_SYNTAX_VARIABLE_DECLARATION_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

class Node::VariableDeclaration: public Node, public std::enable_shared_from_this<VariableDeclaration> {
public:
  VariableDeclaration(std::shared_ptr<Pattern> pattern, std::shared_ptr<Type> type, std::shared_ptr<Node> expression);

  std::shared_ptr<Pattern> pattern;

  std::shared_ptr<Type> type;

  std::shared_ptr<Node> expression;

  void accept(Visitor &visitor) override;
};

#endif
