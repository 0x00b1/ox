#ifndef OXC_MODULE_ITEM_H
#define OXC_MODULE_ITEM_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Declaration.h"
#include "Visitor/Visitor.h"

class Node::ModuleDeclaration: public Node, public std::enable_shared_from_this<ModuleDeclaration> {
public:
  explicit ModuleDeclaration(std::string identifier);

  ModuleDeclaration(std::string identifier, std::vector<std::shared_ptr<Declaration>> items);

  std::string identifier;

  std::vector<std::shared_ptr<Declaration>> items;

  void accept(Visitor &visitor) override;
};

#endif
