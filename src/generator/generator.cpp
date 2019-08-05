#include <iostream>

#include "Generator.h"

void Generator::accept(std::shared_ptr<Node::AnonymousConstant> node) {
  std::cout << "Node::AnonymousConstant" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::Argument> node) {
  std::cout << "Node::Argument" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::ArrayExpression> array_expression) {
  std::cout << "Node::ArrayExpression" << std::endl;

  for (const std::shared_ptr<Node::Expression>& element: array_expression->elements) {
    element->accept(*this);
  }
}

void Generator::accept(std::shared_ptr<Node::ArrayType> node) {
  std::cout << "Node::ArrayType" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::AssignmentStatement> node) {
  std::cout << "Node::AssignmentStatement" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::BlockStatement> node) {
  std::cout << "Node::BlockStatement" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::BooleanLiteralExpression> node) {
  std::cout << "Node::BooleanLiteralExpression" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::BooleanType> node) {
  std::cout << "Node::BooleanType" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::BottomType> node) {
  std::cout << "Node::BottomType" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::CallExpression> node) {
  std::cout << "Node::CallExpression" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::ClosureExpression> node) {
  std::cout << "Node::ClosureExpression" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::ConditionalStatement> node) {
  std::cout << "Node::ConditionalStatement" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::ConstantItem> node) {
  std::cout << "Node::ConstantItem" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::ExpressionStatement> node) {
  std::cout << "Node::ExpressionStatement" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::ExternalPackageItem> node) {
  std::cout << "Node::ExternalPackageItem" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::FloatingPointLiteralExpression> node) {
  std::cout << "Node::FloatingPointLiteralExpression" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::FloatingPointType> node) {
  std::cout << "Node::FloatingPointType" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::FunctionDeclaration> node) {
  std::cout << "Node::FunctionDeclaration" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::FunctionType> node) {
  std::cout << "Node::FunctionType" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::GroupedExpression> node) {
  std::cout << "Node::GroupedExpression" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::Identifier> node) {
  std::cout << "Node::Identifier" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::IndexExpression> node) {
  std::cout << "Node::IndexExpression" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::InfixExpression> node) {
  std::cout << "Node::InfixExpression" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::IntegerLiteralExpression> node) {
  std::cout << "Node::IntegerLiteralExpression" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::IntegerType> node) {
  std::cout << "Node::IntegerType" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::ItemStatement> node) {
  std::cout << "Node::ItemStatement" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::Literal> node) {
  std::cout << "Node::Literal" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::LiteralExpression> node) {
  std::cout << "Node::LiteralExpression" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::LiteralPattern> node) {
  std::cout << "Node::LiteralPattern" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::ModuleItem> node) {
  std::cout << "Node::ModuleItem" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::Name> node) {
  std::cout << "Node::Name" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::OperatorExpression> node) {
  std::cout << "Node::OperatorExpression" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::Parameter> node) {
  std::cout << "Node::Parameter" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::PathExpression> node) {
  std::cout << "Node::PathExpression" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::PathPattern> node) {
  std::cout << "Node::PathPattern" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::PathType> node) {
  std::cout << "Node::PathType" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::PointerType> node) {
  std::cout << "Node::PointerType" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::PostfixExpression> node) {
  std::cout << "Node::PostfixExpression" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::PrefixExpression> node) {
  std::cout << "Node::PrefixExpression" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::ReferencePattern> node) {
  std::cout << "Node::ReferencePattern" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::ReferenceType> node) {
  std::cout << "Node::ReferenceType" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::ReturnStatement> return_statement) {
  std::cout << "Node::ReturnStatement" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::SizeType> node) {
  std::cout << "Node::SizeType" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::SlicePattern> node) {
  std::cout << "Node::SlicePattern" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::SliceType> node) {
  std::cout << "Node::SliceType" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::SubroutineItem> node) {
  std::cout << "Node::SubroutineItem" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::TupleExpression> tuple_expression) {
  std::cout << "Node::TupleExpression" << std::endl;

  for (const std::shared_ptr<Node::Expression>& element: tuple_expression->elements) {
    element->accept(*this);
  }
}

void Generator::accept(std::shared_ptr<Node::TuplePattern> node) {
  std::cout << "Node::TuplePattern" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::TupleType> node) {
  std::cout << "Node::TupleType" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::TypeItem> node) {
  std::cout << "Node::TypeItem" << std::endl;
}

void Generator::accept(std::shared_ptr<Node::Unit> unit) {
  std::cout << "Node::Unit" << std::endl;

  for (const std::shared_ptr<Node::Statement>& statement: unit->statements) {
    statement->accept(*this);
  }
}

void Generator::accept(std::shared_ptr<Node::WildcardPattern> node) {
  std::cout << "Node::WildcardPattern" << std::endl;
}
