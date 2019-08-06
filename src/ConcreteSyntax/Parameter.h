#ifndef OXC_PARAMETER_H
#define OXC_PARAMETER_H

#include <memory>
#include <string>
#include <utility>

#include "Pattern.h"
#include "Position.h"
#include "Type.h"
#include "Visitor.h"

class Node::Parameter: public Node, public std::enable_shared_from_this<Parameter> {
public:
  Parameter(std::string pattern, std::shared_ptr<Type> type);

  std::string pattern;

  std::shared_ptr<Type> type;

  void accept(Visitor &visitor) override;
};

#endif
