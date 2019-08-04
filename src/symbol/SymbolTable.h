#ifndef OXC_SYMBOL_SYMBOL_TABLE_H
#define OXC_SYMBOL_SYMBOL_TABLE_H

#include <string>
#include <vector>

#include "Symbol.h"

class SymbolTable {
public:
  std::string identifier;

  std::vector<Symbol> symbols;

  std::vector<SymbolTable> children;

  virtual Symbol find(std::string identifier);
};

#endif
