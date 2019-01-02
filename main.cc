#include <iostream>
#include "compiler.hh"
#include "ox.hh"

int main (int argc, char *argv[]) {
    int res = 0;

    Compiler compiler;

    for (int i = 1; i < argc; ++i) {
        if (argv[i] == std::string ("-p")) {
            compiler.trace_parsing = true;
        } else if (argv[i] == std::string("-s")) {
            compiler.trace_scanning = true;
        } else if (!compiler.parse(argv[i])) {
            std::cout << compiler.result << '\n';
        } else {
            res = 1;
        }
    }

    Expression expression;
    Integer integer;
    Boolean boolean;

    std::vector<Node*> nodes;

    nodes.push_back(&expression);
    nodes.push_back(&integer);
    nodes.push_back(&boolean);

    Generator generator;

    for (Node* node: nodes) {
        node->accept(generator);
    }

    return res;
}
