#ifndef OXC_TUPLE_TYPE_H
#define OXC_TUPLE_TYPE_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Type.h"
#include "Visitor/Visitor.h"

class Node::TupleType: public Node, public std::enable_shared_from_this<TupleType> {
public:
  explicit TupleType(std::vector<std::shared_ptr<Type>> types);

  std::vector<std::shared_ptr<Type>> types;

  void accept(Visitor &visitor) override;
};

#endif
