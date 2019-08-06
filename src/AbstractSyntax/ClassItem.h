#ifndef OXC_CLASS_ITEM_H
#define OXC_CLASS_ITEM_H

#include <memory>
#include <optional>
#include <string>
#include <utility>

#include "Expression.h"
#include "Statement.h"
#include "Visitor/Visitor.h"

class Node::ClassItem: public Node, public std::enable_shared_from_this<ClassItem> {
public:
  ClassItem();

  void accept(Visitor &visitor) override;
};

#endif
