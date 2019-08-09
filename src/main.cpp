#include <iostream>

#include "ox/AbstractSyntax.h"
#include "compiler.hh"
#include "ox/compiler.h"

int main(int argc, const char * argv[]) {
  Compiler compiler;

  for (int index = 1; index < argc; ++index) {
    if (argv[index] == std::string("-p")) {
      compiler.trace_parsing = true;
    } else if (argv[index] == std::string("-s")) {
      compiler.trace_scanning = true;
    } else if (!compiler.parse(argv[index])) {

    } else {

    }
  }

  compiler.resolve_names();
}
