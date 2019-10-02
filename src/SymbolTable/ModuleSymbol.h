#ifndef OXC_OXC_SYMBOL_TABLE_MODULE_SYMBOL_H
#define OXC_OXC_SYMBOL_TABLE_MODULE_SYMBOL_H

#include <string>
#include <vector>

class ModuleSymbol {
public:
  explicit ModuleSymbol(std::string name, std::string type);

  std::string name;

  std::string type;
};

#endif
