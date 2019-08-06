#ifndef OXC_SYMBOL_SUBROUTINE_SYMBOL_TABLE_H
#define OXC_SYMBOL_SUBROUTINE_SYMBOL_TABLE_H

#include <vector>

#include "SymbolTable.h"

class SubroutineSymbolTable: SymbolTable {
public:
  std::vector<Symbol> parameters;
};

#endif
