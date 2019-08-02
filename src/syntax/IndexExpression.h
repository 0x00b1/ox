#ifndef OXC_INDEX_EXPRESSION_H
#define OXC_INDEX_EXPRESSION_H

#include <memory>
#include <string>
#include <utility>

#include "Expression.h"
#include "Visitor.h"

class Node::IndexExpression: public Expression, public std::enable_shared_from_this<IndexExpression> {
public:
  IndexExpression(std::shared_ptr<Expression> container, std::shared_ptr<Expression> index);

  std::shared_ptr<Expression> container;

  std::shared_ptr<Expression> index;

  void accept(Visitor &visitor) override;
};

#endif
