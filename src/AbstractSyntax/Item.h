#ifndef OXC_ITEM_H
#define OXC_ITEM_H

#include <memory>
#include <string>
#include <utility>

#include "Node.h"
#include "Visitor/Visitor.h"

class Node::Item: public Node, public std::enable_shared_from_this<Item> {
public:
  explicit Item(std::shared_ptr<Node> node);

  std::shared_ptr<Node> node;

  void accept(Visitor &visitor) override;
};

#endif
