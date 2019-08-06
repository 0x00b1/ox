#ifndef OXC_IDENTIFIER_PATTERN_H
#define OXC_IDENTIFIER_PATTERN_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Expression.h"
#include "PrefixExpression.h"

class Node::IdentifierPattern: public Node, public std::enable_shared_from_this<IdentifierPattern> {
public:
  explicit IdentifierPattern(std::shared_ptr<Identifier> identifier);

  std::shared_ptr<Identifier> identifier;

  void accept(Visitor &visitor) override;
};

#endif
