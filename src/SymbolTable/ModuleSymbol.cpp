#include "ModuleSymbol.h"

ModuleSymbol::ModuleSymbol(std::string name, std::string type) {
  this->name = std::move(name);

  this->type = std::move(type);
}
