#include "compiler.hh"
#include "parser.hh"

Compiler::Compiler() = default;

void Compiler::resolve_names() {
  name_resolution.accept(this->translation_unit);

  this->symbol_table = name_resolution.symbol_table;
}

int Compiler::parse(const std::string &f) {
  file = f;

  location.initialize (&file);

  scan_begin();

  yy::parser parse(*this);

  parse.set_debug_level(trace_parsing);

  int res = parse();

  scan_end();

  return res;
}
