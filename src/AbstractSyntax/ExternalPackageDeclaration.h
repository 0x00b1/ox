#ifndef OXC_ABSTRACT_SYNTAX_EXTERNAL_PACKAGE_ITEM_H
#define OXC_ABSTRACT_SYNTAX_EXTERNAL_PACKAGE_ITEM_H

#include <memory>
#include <string>
#include <utility>

#include "Declaration.h"
#include "ox/Visitor.h"

class Node::ExternalPackageDeclaration: public Node, public std::enable_shared_from_this<ExternalPackageDeclaration> {
public:
  ExternalPackageDeclaration();

  void accept(Visitor &visitor) override;
};

#endif
