#ifndef OXC_FUNCTION_TYPE_HH
#define OXC_FUNCTION_TYPE_HH

#include <memory>
#include <string>
#include <utility>

#include "Visitor.hh"

class Node::FunctionType: public Node::Node, public std::enable_shared_from_this<FunctionType> {
public:
  explicit FunctionType(std::shared_ptr<FunctionDeclaration> declaration);

  std::shared_ptr<FunctionDeclaration> declaration;

  void accept(Visitor &visitor) override;
};

#endif
