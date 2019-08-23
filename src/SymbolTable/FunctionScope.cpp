#include "FunctionScope.h"

FunctionScope::FunctionScope(std::string name) {
  this->name = std::move(name);
}
