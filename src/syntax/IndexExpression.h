#ifndef OXC_INDEX_EXPRESSION_H
#define OXC_INDEX_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "Visitor.h"

class Node::IndexExpression: public Node, public std::enable_shared_from_this<IndexExpression> {
public:
  IndexExpression(std::shared_ptr<Node> container, std::shared_ptr<Node> index);

  std::shared_ptr<Node> container;

  std::shared_ptr<Node> index;

  void accept(Visitor &visitor) override;
};

#endif
