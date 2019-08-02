#ifndef OXC_TUPLE_TYPE_HH
#define OXC_TUPLE_TYPE_HH

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Visitor.hh"

class Node::TupleType: public Type, public std::enable_shared_from_this<TupleType> {
public:
  explicit TupleType(std::vector<std::shared_ptr<Type>> types);

  std::vector<std::shared_ptr<Type>> types;

  void accept(Visitor &visitor) override;
};

#endif
