#ifndef OXC_EXTERNAL_PACKAGE_ITEM_H
#define OXC_EXTERNAL_PACKAGE_ITEM_H

#include <memory>
#include <string>
#include <utility>

#include "Declaration.h"
#include "Visitor/Visitor.h"

class Node::ExternalPackageDeclaration: public Node, public std::enable_shared_from_this<ExternalPackageDeclaration> {
public:
  explicit ExternalPackageDeclaration(std::string identifier);

  ExternalPackageDeclaration(std::string identifier, std::string alias);

  std::string identifier;

  std::string alias;

  void accept(Visitor &visitor) override;
};

#endif
