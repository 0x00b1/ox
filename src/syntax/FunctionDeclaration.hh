#ifndef OXC_FUNCTION_DECLARATION_HH
#define OXC_FUNCTION_DECLARATION_HH

#include <memory>
#include <string>
#include <utility>

#include "Statement.hh"
#include "Visitor.hh"

class Node::FunctionDeclaration: public Statement, public std::enable_shared_from_this<FunctionDeclaration> {
public:
  FunctionDeclaration();

  void accept(Visitor &visitor) override;
};

#endif
