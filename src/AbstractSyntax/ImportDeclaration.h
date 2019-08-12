#ifndef OXC_ABSTRACT_SYNTAX_IMPORT_DECLARATION_H
#define OXC_ABSTRACT_SYNTAX_IMPORT_DECLARATION_H

#include <memory>
#include <string>
#include <utility>

#include "ox/Visitor.h"

#include "Declaration.h"

class Node::ImportDeclaration: public Node, public std::enable_shared_from_this<ImportDeclaration> {
public:
  ImportDeclaration();

  void accept(Visitor &visitor) override;
};

#endif
