#include <iostream>

#include "include/compiler.hh"
#include "include/ast.hh"
#include "include/generator.hh"

int main (int argc, char *argv[]) {
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

    compiler.root->accept(generator);

    return code;
}
