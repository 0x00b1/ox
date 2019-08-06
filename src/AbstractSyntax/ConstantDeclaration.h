#ifndef OXC_CONSTANT_ITEM_H
#define OXC_CONSTANT_ITEM_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "Declaration.h"
#include "Type.h"
#include "Visitor/Visitor.h"

class Node::ConstantDeclaration: public Node, public std::enable_shared_from_this<ConstantDeclaration> {
public:
  ConstantDeclaration(std::string identifier, std::shared_ptr<Type> type, std::shared_ptr<Node> expression);

  std::string identifier;

  std::shared_ptr<Type> type;

  std::shared_ptr<Node> expression;

  void accept(Visitor &visitor) override;
};

#endif