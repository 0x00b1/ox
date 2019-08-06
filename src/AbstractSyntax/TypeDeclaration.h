#ifndef OXC_TYPE_ITEM_H
#define OXC_TYPE_ITEM_H

#include <memory>
#include <string>
#include <utility>

#include "Declaration.h"
#include "Type.h"
#include "Visitor/Visitor.h"

class Node::TypeDeclaration: public Node, public std::enable_shared_from_this<TypeDeclaration> {
public:
  TypeDeclaration(std::string identifier, std::shared_ptr<Type> type);

  std::string identifier;

  std::shared_ptr<Type> type;

  void accept(Visitor &visitor) override;
};

#endif
