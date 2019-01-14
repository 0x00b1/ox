#include <iostream>

#include "include/compiler.hh"
#include "include/syntax.hh"

int main(int argc, const char * argv[]) {
    int code = 0;

    Compiler compiler;

    for (int i = 1; i < argc; ++i) {
        if (argv[i] == std::string ("-p")) {
            compiler.trace_parsing = true;
        } else if (argv[i] == std::string("-s")) {
            compiler.trace_scanning = true;
        } else if (!compiler.parse(argv[i])) {
            std::cout << compiler.result << '\n';
        } else {
            code = 1;
        }
    }

    /*
     * Example compiler pass
     */
    Generator generator;

    std::vector<std::shared_ptr<AST::Expression>> elements;

    std::shared_ptr<Expression::IntegerLiteral> a(new Expression::IntegerLiteral("1"));
    std::shared_ptr<Expression::IntegerLiteral> b(new Expression::IntegerLiteral("2"));
    std::shared_ptr<Expression::IntegerLiteral> c(new Expression::IntegerLiteral("3"));

    elements.push_back(a);
    elements.push_back(b);
    elements.push_back(c);

    std::shared_ptr<Expression::Array> x(new Expression::Array(elements));

    x->accept(generator);

    std::cout << std::endl;

    return code;
}
