#ifndef OXC_ABSTRACT_SYNTAX_DECLARATION_H
#define OXC_ABSTRACT_SYNTAX_DECLARATION_H

#include <memory>
#include <optional>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Node.h"

class Node::Declaration: public Node, public std::enable_shared_from_this<Declaration> {
public:
  explicit Declaration(std::shared_ptr<Node> node);
  
  Declaration(std::shared_ptr<Identifier> identifier, std::shared_ptr<Node> node);

  std::optional<std::shared_ptr<Identifier>> identifier;

  std::shared_ptr<Node> node;

  void accept(Visitor &visitor) override;
};

#endif
