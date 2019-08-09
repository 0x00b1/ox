#include <iostream>

#include "ox/SymbolTable.h"

#include "NameResolution.h"

void NameResolution::accept(std::shared_ptr<Node::AnonymousConstant> anonymous_constant) {
  std::cout << "Node::AnonymousConstant" << std::endl;

  anonymous_constant->expression->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::Argument> argument) {
  std::cout << "Node::Argument" << std::endl;

  argument->pattern->accept(*this);

  argument->type->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::ArrayExpression> array_expression) {
  std::cout << "Node::ArrayExpression" << std::endl;

  for (const std::shared_ptr<Node::Node>& element: array_expression->elements) {
    element->accept(*this);
  }
}

void NameResolution::accept(std::shared_ptr<Node::ArrayType> array_type) {
  std::cout << "Node::ArrayType" << std::endl;

  array_type->type->accept(*this);

  array_type->anonymous_constant->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::AssignmentStatement> assignment_statement) {
  std::cout << "Node::AssignmentStatement" << std::endl;

  assignment_statement->pattern->accept(*this);

  assignment_statement->type->accept(*this);

  assignment_statement->expression->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::BlockStatement> block_statement) {
  std::cout << "Node::BlockStatement" << std::endl;

  for (const std::shared_ptr<Node::Statement>& statement: block_statement->statements) {
    statement->accept(*this);
  }
}

void NameResolution::accept(std::shared_ptr<Node::BooleanLiteralExpression> node) {
  std::cout << "Node::BooleanLiteralExpression" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::BooleanType> node) {
  std::cout << "Node::BooleanType" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::BottomType> node) {
  std::cout << "Node::BottomType" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::CallExpression> call_expression) {
  std::cout << "Node::CallExpression" << std::endl;

  call_expression->subroutine->accept(*this);

  for (const std::shared_ptr<Node::Node>& parameter: call_expression->parameters) {
    parameter->accept(*this);
  }
}

void NameResolution::accept(std::shared_ptr<Node::ClassDeclaration> class_item) {
  std::cout << "Node::ClassDeclaration" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::ClosureExpression> node) {
  std::cout << "Node::ClosureExpression" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::ConditionalStatement> conditional_statement) {
  std::cout << "Node::ConditionalStatement" << std::endl;

  conditional_statement->predicate->accept(*this);

  conditional_statement->consequent->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::ConstantDeclaration> node) {
  std::cout << "Node::ConstantDeclaration" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::Expression> expression) {
  std::cout << "Node::Expression" << std::endl;

  expression->node->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::ExpressionStatement> expression_statement) {
  std::cout << "Node::ExpressionStatement" << std::endl;

  expression_statement->expression->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::ExternalPackageDeclaration> node) {
  std::cout << "Node::ExternalPackageDeclaration" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::FloatingPointLiteralExpression> node) {
  std::cout << "Node::FloatingPointLiteralExpression" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::FloatingPointType> node) {
  std::cout << "Node::FloatingPointType" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::FunctionDeclaration> node) {
  std::cout << "Node::FunctionDeclaration" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::FunctionPrototype> node) {
  std::cout << "Node::FunctionPrototype" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::FunctionType> function_type) {
  std::cout << "Node::FunctionType" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::GroupedExpression> grouped_expression) {
  std::cout << "Node::GroupedExpression" << std::endl;

  grouped_expression->operator_expression->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::Identifier> node) {
  std::cout << "Node::Identifier" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::IdentifierPattern> node) {
  std::cout << "Node::IdentifierPattern" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::IndexExpression> index_expression) {
  std::cout << "Node::IndexExpression" << std::endl;

  index_expression->container->accept(*this);

  index_expression->index->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::InfixExpression> infix_expression) {
  std::cout << "Node::InfixExpression" << std::endl;

  infix_expression->expression->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::InfixOperation> node) {

}

void NameResolution::accept(std::shared_ptr<Node::IntegerLiteralExpression> integer_literal_expression) {
  std::cout << "Node::IntegerLiteralExpression" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::IntegerType> integer_type) {
  std::cout << "Node::IntegerType" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::Declaration> item) {
  std::cout << "Node::Declaration" << std::endl;

  item->node->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::DeclarationStatement> item_statement) {
  std::cout << "Node::DeclarationStatement" << std::endl;

  item_statement->item->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::Literal> literal) {
  std::cout << "Node::Literal" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::LiteralExpression> literal_expression) {
  std::cout << "Node::LiteralExpression" << std::endl;

  literal_expression->node->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::LiteralPattern> literal_pattern) {
  std::cout << "Node::LiteralPattern" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::ModuleDeclaration> module_item) {
  std::cout << "Node::ModuleDeclaration" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::Name> name) {
  std::cout << "Node::Name" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::OperatorExpression> operator_expression) {
  std::cout << "Node::OperatorExpression" << std::endl;

  operator_expression->prefix_expression->accept(*this);

  for (const std::shared_ptr<Node::InfixExpression>& infix_expression: operator_expression->infix_expressions) {
    infix_expression->accept(*this);
  }
}

void NameResolution::accept(std::shared_ptr<Node::Parameter> parameter) {
  std::cout << "Node::Parameter" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::Path> path_segment) {
  std::cout << "Node::Path" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::PathExpression> path_expression) {
  std::cout << "Node::PathExpression" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::PathPattern> path_pattern) {
  std::cout << "Node::PathPattern" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::PathSegment> path_segment) {
  std::cout << "Node::PathSegment" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::PathType> path_type) {
  std::cout << "Node::PathType" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::Pattern> pattern) {
  std::cout << "Node::Pattern" << std::endl;

  pattern->node->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::PointerType> pointer_type) {
  std::cout << "Node::PointerType" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::PostfixExpression> postfix_expression) {
  std::cout << "Node::PostfixExpression" << std::endl;

  postfix_expression->expression->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::PrefixExpression> prefix_expression) {
  std::cout << "Node::PrefixExpression" << std::endl;

  prefix_expression->postfix_expression->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::PrefixOperation> node) {

}

void NameResolution::accept(std::shared_ptr<Node::ReferencePattern> reference_pattern) {
  std::cout << "Node::ReferencePattern" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::ReferenceType> reference_type) {
  std::cout << "Node::ReferenceType" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::ReturnStatement> return_statement) {
  std::cout << "Node::ReturnStatement" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::SizeType> size_type) {
  std::cout << "Node::SizeType" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::SlicePattern> slice_pattern) {
  std::cout << "Node::SlicePattern" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::SliceType> slice_type) {
  std::cout << "Node::SliceType" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::Statement> statement) {
  std::cout << "Node::Statement" << std::endl;

  statement->node->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::SubroutineDeclaration> subroutine_item) {
  std::cout << "Node::SubroutineDeclaration" << std::endl;

  subroutine_item->function_declaration->accept(*this);

  subroutine_item->block_statement->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::TupleExpression> tuple_expression) {
  std::cout << "Node::TupleExpression" << std::endl;

  for (const std::shared_ptr<Node::Node>& element: tuple_expression->elements) {
    element->accept(*this);
  }
}

void NameResolution::accept(std::shared_ptr<Node::TuplePattern> tuple_pattern) {
  std::cout << "Node::TuplePattern" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::TupleType> tuple_type) {
  std::cout << "Node::TupleType" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::Type> type) {
  std::cout << "Node::Type" << std::endl;

  type->node->accept(*this);
}

void NameResolution::accept(std::shared_ptr<Node::TypeDeclaration> type_item) {
  std::cout << "Node::TypeDeclaration" << std::endl;
}

void NameResolution::accept(std::shared_ptr<Node::TranslationUnit> unit) {
  std::cout << "Node::TranslationUnit" << std::endl;

  for (const std::shared_ptr<Node::Statement>& statement: unit->statements) {
    statement->accept(*this);
  }
}

void NameResolution::accept(std::shared_ptr<Node::WildcardPattern> node) {
  std::cout << "Node::WildcardPattern" << std::endl;
}
