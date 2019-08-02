#ifndef OXC_PARAMETER_H
#define OXC_PARAMETER_H

#include <memory>
#include <string>
#include <utility>

#include "Visitor.h"

class Node::Parameter: public Node, public std::enable_shared_from_this<Parameter> {
public:
  explicit Parameter(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
