#ifndef OXC_ARGUMENT_HH
#define OXC_ARGUMENT_HH

#include <memory>
#include <string>
#include <utility>

#include "Position.hh"
#include "Visitor.hh"

class Node::Argument: public Node, public std::enable_shared_from_this<Argument> {
public:
  Argument(std::shared_ptr<Pattern> pattern, std::shared_ptr<Type> type);

  std::shared_ptr<Pattern> pattern;

  std::shared_ptr<Type> type;

  void accept(Visitor &visitor) override;
};

#endif
