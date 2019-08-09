#ifndef OX_COMPILER_HH
#define OX_COMPILER_HH

#include <string>
#include <map>

#include "ox/compiler.h"
#include "parser.hh"

// Give Flex the prototype of yylex we want ...
#define YY_DECL yy::parser::symbol_type yylex(Compiler& compiler)

// ... and declare it for the parser's sake.
YY_DECL;

class Compiler {
public:
  Compiler();

  std::shared_ptr<Node::TranslationUnit> translation_unit;

  // The name of the file being parsed.
  std::string file;

  NameResolution name_resolution;

  // Whether to generate parser debug traces.
  bool trace_parsing = false;

  // Whether to generate scanner debug traces.
  bool trace_scanning = false;

  // The token's location used by the scanner.
  yy::location location;

  void resolve_names();

  int parse(const std::string &f);

  // Handling the scanner.
  void scan_begin();
  void scan_end();
};

#endif
