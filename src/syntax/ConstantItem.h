#ifndef OXC_CONSTANT_ITEM_H
#define OXC_CONSTANT_ITEM_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "Item.h"
#include "Type.h"
#include "Visitor.h"

class Node::ConstantItem: public Node, public std::enable_shared_from_this<ConstantItem> {
public:
  ConstantItem(std::string identifier, std::shared_ptr<Type> type, std::shared_ptr<Node> expression);

  std::string identifier;

  std::shared_ptr<Type> type;

  std::shared_ptr<Node> expression;

  void accept(Visitor &visitor) override;
};

#endif
