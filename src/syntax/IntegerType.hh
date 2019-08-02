#ifndef OXC_INTEGER_TYPE_HH
#define OXC_INTEGER_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "Type.hh"
#include "Visitor.hh"

class Node::IntegerType: public Type, public std::enable_shared_from_this<IntegerType> {
public:
  IntegerType();

  void accept(Visitor &visitor) override;
};

#endif
