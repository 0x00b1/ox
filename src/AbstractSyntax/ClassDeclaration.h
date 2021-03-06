#ifndef OXC_ABSTRACT_SYNTAX_CLASS_ITEM_H
#define OXC_ABSTRACT_SYNTAX_CLASS_ITEM_H

#include <memory>
#include <optional>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Expression.h"
#include "Statement.h"

class Node::ClassDeclaration: public Node, public std::enable_shared_from_this<ClassDeclaration> {
public:
  ClassDeclaration();

  void accept(Visitor &visitor) override;
};

#endif
