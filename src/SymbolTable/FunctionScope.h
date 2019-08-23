#ifndef OXC_SYMBOL_TABLE_FUNCTION_SCOPE_H
#define OXC_SYMBOL_TABLE_FUNCTION_SCOPE_H

#include <string>

#include "SymbolTable.h"

class FunctionScope {
public:
  explicit FunctionScope(std::string name);

  std::string name;

  SymbolTable symbol_table;
};

#endif
