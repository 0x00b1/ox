#include "include/compiler.hh"
#include "parser.hh"

Compiler::Compiler(): trace_parsing(false), trace_scanning(false) {
    variables["one"] = 1;
    variables["two"] = 2;
}

int Compiler::parse(const std::string &f) {
    file = f;
    location.initialize (&file);
    scan_begin ();
    yy::parser parse (*this);
    parse.set_debug_level (trace_parsing);
    int res = parse ();
    scan_end ();
    return res;
}
