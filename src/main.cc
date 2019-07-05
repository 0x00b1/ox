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

    Generator generator;

    /*
     * Example compiler pass
     */
    std::shared_ptr<Expression::IntegerLiteral> example(new Expression::IntegerLiteral("100"));

    example->accept(generator);

    std::cout << std::endl;

    return code;
}
