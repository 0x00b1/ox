#ifndef OXC_ABSTRACT_SYNTAX_ARGUMENT_H
#define OXC_ABSTRACT_SYNTAX_ARGUMENT_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Pattern.h"
#include "Position.h"
#include "Type.h"

class Node::Argument: public Node, public std::enable_shared_from_this<Argument> {
public:
  Argument(std::shared_ptr<Pattern> pattern, std::shared_ptr<Type> type);

  std::shared_ptr<Pattern> pattern;

  std::shared_ptr<Type> type;

  void accept(Visitor &visitor) override;
};

#endif
