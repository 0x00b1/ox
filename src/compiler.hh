#ifndef OX_COMPILER_HH
#define OX_COMPILER_HH

#include <string>
#include <map>

#include "ox/compiler.h"
#include "ox/SymbolTable.h"

#include "parser.hh"

// Give Flex the prototype of yylex we want ...
#define YY_DECL yy::parser::symbol_type yylex(Compiler& compiler)

// ... and declare it for the parser's sake.
YY_DECL;

class Compiler {
public:
  Compiler();

  std::string file;

  yy::location location;

  NameResolution name_resolution;

  std::shared_ptr<SymbolTable> symbol_table;

  std::shared_ptr<Node::TranslationUnit> translation_unit;

  // Whether to generate parser debug traces.
  bool trace_parsing = false;

  // Whether to generate scanner debug traces.
  bool trace_scanning = false;

  void resolve_names();

  int parse(const std::string &f);

  void scan_begin();
  void scan_end();
};

#endif
