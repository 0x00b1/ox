#ifndef OXC_IDENTIFIER_PATTERN_H
#define OXC_IDENTIFIER_PATTERN_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "PrefixExpression.h"
#include "Visitor.h"

class Node::IdentifierPattern: public Node, public std::enable_shared_from_this<IdentifierPattern> {
public:
  explicit IdentifierPattern(std::string identifier);

  std::string identifier;

  void accept(Visitor &visitor) override;
};

#endif
