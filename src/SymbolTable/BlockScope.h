#ifndef OXC_SYMBOL_TABLE_BLOCK_SCOPE_H
#define OXC_SYMBOL_TABLE_BLOCK_SCOPE_H

#include "SymbolTable.h"

class BlockScope {
public:
  BlockScope();

  SymbolTable symbol_table;
};

#endif
