#include "include/generator.hh"

void Generator::visit(const AST::Node &node) {
    std::cout << "generating Node" << std::endl;
}

void Generator::visit(const AST::Root &root) {
    std::cout << "generating Root" << std::endl;

    for (auto node: root.nodes) {
        node->accept(*this);
    }
}

void Generator::visit(const AST::Statement &node) {
    std::cout << "generating STATEMENT" << std::endl;
}

void Generator::visit(const AST::Expression &node) {
    std::cout << "generating EXPRESSION" << std::endl;
}

void Generator::visit(const AST::Declaration &node) {
    std::cout << "generating DECLARATION" << std::endl;
}

void Generator::visit(const AST::Argument &node) {
    std::cout << "generating Argument" << std::endl;
}

void Generator::visit(const AST::ArrayExpression &node) {
    std::cout << "generating ArrayExpression" << std::endl;
}

void Generator::visit(const AST::UnaryOperationExpression &node) {
    std::cout << "generating UnaryOperationExpression" << std::endl;
}

void Generator::visit(const AST::BlockExpression &node) {
    std::cout << "generating BlockExpression" << std::endl;
}

void Generator::visit(const AST::BooleanLiteralExpression &node) {
    std::cout << "generating BooleanLiteralExpression" << std::endl;
}

void Generator::visit(const AST::BreakExpression &node) {
    std::cout << "generating BreakExpression" << std::endl;
}

void Generator::visit(const AST::CallExpression &node) {
    std::cout << "generating CallExpression" << std::endl;
}

void Generator::visit(const AST::ClosureExpression &node) {
    std::cout << "generating ClosureExpression" << std::endl;
}

void Generator::visit(const AST::ConstantDeclaration &node) {
    std::cout << "generating ConstantDeclaration" << std::endl;
}

void Generator::visit(const AST::ContinueExpression &node) {
    std::cout << "generating ContinueExpression" << std::endl;
}

void Generator::visit(const AST::FloatingPointLiteralExpression &node) {
    std::cout << "generating FloatingPointLiteralExpression" << std::endl;
}

void Generator::visit(const AST::ForLoopExpression &node) {
    std::cout << "generating FloatingPointLiteralExpression" << std::endl;
}

void Generator::visit(const AST::GenericParameter &node) {
    std::cout << "generating GenericParameter" << std::endl;
}

void Generator::visit(const AST::IntegerLiteralExpression &node) {
    std::cout << "generating IntegerLiteralExpression" << std::endl;
}

void Generator::visit(const AST::LabelDeclaration &node) {
    std::cout << "generating LabelDeclaration" << std::endl;
}

void Generator::visit(const AST::EnumerationDeclaration &node) {
    std::cout << "generating EnumerationDeclaration" << std::endl;
}

void Generator::visit(const AST::ModuleDeclaration &node) {
    std::cout << "generating ModuleDeclaration" << std::endl;
}

void Generator::visit(const AST::RangeExpression &node) {
    std::cout << "generating RangeExpression" << std::endl;
}

void Generator::visit(const AST::RecordExpression &node) {
    std::cout << "generating RecordExpression" << std::endl;
}

void Generator::visit(const AST::RecordDeclaration &node) {
    std::cout << "generating RecordDeclaration" << std::endl;
}

void Generator::visit(const AST::RecordFieldDeclaration &node) {
    std::cout << "generating RecordFieldDeclaration" << std::endl;
}

void Generator::visit(const AST::ReturnExpression &node) {
    std::cout << "generating ReturnExpression" << std::endl;
}

void Generator::visit(const AST::SubroutineDeclaration &node) {
    std::cout << "generating SubroutineDeclaration" << std::endl;
}

void Generator::visit(const AST::SwitchExpression &node) {
    std::cout << "generating SwitchExpression" << std::endl;
}

void Generator::visit(const AST::TupleExpression &node) {
    std::cout << "generating TypeAliasDeclaration" << std::endl;
}

void Generator::visit(const AST::TypeAliasDeclaration &node) {
    std::cout << "generating TypeAliasDeclaration" << std::endl;
}

void Generator::visit(const AST::BinaryOperationExpression &node) {
    std::cout << "generating BinaryOperationExpression" << std::endl;
}

void Generator::visit(const AST::UnionDeclaration &node) {
    std::cout << "generating UnionDeclaration" << std::endl;
}

void Generator::visit(const AST::WhileLoopExpression &node) {
    std::cout << "generating WhileLoopExpression" << std::endl;
}

void Generator::visit(const AST::ConditionalExpression &node) {
    std::cout << "generating ConditionalExpression" << std::endl;
}

void Generator::visit(const AST::Parameter &node) {
    std::cout << "generating Parameter" << std::endl;
}

void Generator::visit(const AST::SubscriptExpression &node) {
    std::cout << "generating SubscriptExpression" << std::endl;
}

void Generator::visit(const AST::TypeSignature &node) {
    std::cout << "generating TypeSignature" << std::endl;
}
