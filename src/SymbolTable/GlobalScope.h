#ifndef OXC_SYMBOL_TABLE_GLOBAL_SCOPE_H
#define OXC_SYMBOL_TABLE_GLOBAL_SCOPE_H

#include <optional>
#include <vector>

#include "ModuleScope.h"

class GlobalScope {
public:
  GlobalScope();

  std::vector<ModuleScope> modules;

  SymbolTable symbol_table;
};

#endif
