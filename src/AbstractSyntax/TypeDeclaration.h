#ifndef OXC_ABSTRACT_SYNTAX_TYPE_ITEM_H
#define OXC_ABSTRACT_SYNTAX_TYPE_ITEM_H

#include <memory>
#include <string>
#include <utility>

#include "Declaration.h"
#include "Type.h"
#include "ox/Visitor.h"

class Node::TypeDeclaration: public Node, public std::enable_shared_from_this<TypeDeclaration> {
public:
  explicit TypeDeclaration(std::shared_ptr<Type> type);

  std::shared_ptr<Type> type;

  void accept(Visitor &visitor) override;
};

#endif
