#ifndef OXC_ABSTRACT_SYNTAX_CONSTANT_ITEM_H
#define OXC_ABSTRACT_SYNTAX_CONSTANT_ITEM_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Expression.h"
#include "Declaration.h"
#include "Type.h"

class Node::ConstantDeclaration: public Node, public std::enable_shared_from_this<ConstantDeclaration> {
public:
  ConstantDeclaration(std::shared_ptr<Type> type, std::shared_ptr<Node> expression);

  std::shared_ptr<Type> type;

  std::shared_ptr<Node> expression;

  void accept(Visitor &visitor) override;
};

#endif
