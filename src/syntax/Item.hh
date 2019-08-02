#ifndef OXC_ITEM_HH
#define OXC_ITEM_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::Item: public Node, public std::enable_shared_from_this<Item> {
public:
  explicit Item(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
