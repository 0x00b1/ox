#ifndef OXC_MODULE_ITEM_H
#define OXC_MODULE_ITEM_H

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "ox/Visitor.h"

#include "Declaration.h"

class Node::ModuleDeclaration: public Node, public std::enable_shared_from_this<ModuleDeclaration> {
public:
  ModuleDeclaration();

  explicit ModuleDeclaration(std::vector<std::shared_ptr<Declaration>> items);

  std::vector<std::shared_ptr<Declaration>> items;

  void accept(Visitor &visitor) override;
};

#endif
