#ifndef OXC_ABSTRACT_SYNTAX_PARAMETER_H
#define OXC_ABSTRACT_SYNTAX_PARAMETER_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Pattern.h"
#include "Position.h"
#include "Type.h"

class Node::Parameter: public Node, public std::enable_shared_from_this<Parameter> {
public:
  Parameter(std::shared_ptr<Pattern> pattern, std::shared_ptr<Type> type);

  std::shared_ptr<Pattern> pattern;

  std::shared_ptr<Type> type;

  void accept(Visitor &visitor) override;
};

#endif
