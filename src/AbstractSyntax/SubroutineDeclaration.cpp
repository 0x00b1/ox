#include "SubroutineDeclaration.h"

Node::SubroutineDeclaration::SubroutineDeclaration(std::shared_ptr<FunctionDeclaration> function_declaration, std::shared_ptr<BlockStatement> block_statement) {
  this->function_declaration = std::move(function_declaration);

  this->block_statement = std::move(block_statement);
}

void Node::SubroutineDeclaration::accept(Visitor &visitor) {
  std::shared_ptr<SubroutineDeclaration> p{shared_from_this()};

  visitor.accept(p);
}
