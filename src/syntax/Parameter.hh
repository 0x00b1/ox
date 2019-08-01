#ifndef OXC_PARAMETER_HH
#define OXC_PARAMETER_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"


class Node::Parameter : public Node::Node, public std::enable_shared_from_this<Parameter> {
public:
  explicit Parameter(std::string value);

  std::string value;

  void accept(Visitor &visitor) override;
};

#endif
