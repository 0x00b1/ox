#ifndef OXC_ABSTRACT_SYNTAX_VARIABLE_DECLARATION_H
#define OXC_ABSTRACT_SYNTAX_VARIABLE_DECLARATION_H

#include <memory>
#include <optional>
#include <string>
#include <utility>

#include "ox/Visitor.h"

class Node::VariableDeclaration: public Node, public std::enable_shared_from_this<VariableDeclaration> {
public:
  /*
   *    variable x;
   */
  explicit VariableDeclaration(std::shared_ptr<Pattern> pattern);

  /*
   *    variable x: Boolean;
   */
  VariableDeclaration(std::shared_ptr<Pattern> pattern, std::shared_ptr<Type> type);

  /*
   *    variable x ← True;
   */
  VariableDeclaration(std::shared_ptr<Pattern> pattern, std::shared_ptr<Node> expression);

  /*
   *    variable x: Boolean ← True;
   */
  VariableDeclaration(std::shared_ptr<Pattern> pattern, std::shared_ptr<Type> type, std::shared_ptr<Node> expression);

  std::shared_ptr<Pattern> pattern;

  std::optional<std::shared_ptr<Type>> type;

  std::optional<std::shared_ptr<Node>> expression;

  void accept(Visitor &visitor) override;
};

#endif
