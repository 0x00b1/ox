#ifndef OX_COMPILER_HH
#define OX_COMPILER_HH

#include <string>
#include <map>

#include "parser.hh"

// Give Flex the prototype of yylex we want ...
#define YY_DECL yy::parser::symbol_type yylex(Compiler& compiler)

// ... and declare it for the parser's sake.
YY_DECL;

class Compiler {
public:
    Compiler();

    std::map<std::string, int> variables;

    std::vector<std::shared_ptr<Node::Statement>> nodes;

    std::shared_ptr<Node::TranslationUnit> unit;

    int result;

    // Run the parser on file F. Return 0 on success.
    int parse(const std::string& f);

    // The name of the file being parsed.
    std::string file;

    // Whether to generate parser debug traces.
    bool trace_parsing;

    // Handling the scanner.
    void scan_begin();
    void scan_end();

    // Whether to generate scanner debug traces.
    bool trace_scanning;

    // The token's location used by the scanner.
    yy::location location;
};

#endif
