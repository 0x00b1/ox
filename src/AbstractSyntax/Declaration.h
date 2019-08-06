#ifndef OXC_DECLARATION_H
#define OXC_DECLARATION_H

#include <memory>
#include <optional>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Identifier.h"
#include "Node.h"

class Node::Declaration: public Node, public std::enable_shared_from_this<Declaration> {
public:
  explicit Declaration(std::shared_ptr<Node> node);
  
  Declaration(Identifier identifier, std::shared_ptr<Node> node);

  std::optional<Identifier> identifier;

  std::shared_ptr<Node> node;

  void accept(Visitor &visitor) override;
};

#endif
