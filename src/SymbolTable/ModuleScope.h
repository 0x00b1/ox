#ifndef OXC_SYMBOL_TABLE_MODULE_SCOPE_H
#define OXC_SYMBOL_TABLE_MODULE_SCOPE_H

#include <string>
#include <vector>

#include "FunctionScope.h"

class ModuleScope {
public:
  explicit ModuleScope(std::string name);

  std::string name;

  std::vector<FunctionScope> functions;

  SymbolTable symbol_table;
};

#endif
