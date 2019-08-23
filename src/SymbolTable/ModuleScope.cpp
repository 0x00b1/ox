#include "ModuleScope.h"

ModuleScope::ModuleScope(std::string name) {
  this->name = std::move(name);
}
