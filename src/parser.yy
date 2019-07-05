%skeleton "lalr1.cc" /* -*- C++ -*- */

%require "3.2"

%defines

%define api.token.constructor

%define api.value.type variant

%define parse.assert

%code requires {
  #include <string>

  #include "include/ast.hh"

  class Compiler;
}

// The parsing context.
%param {
    Compiler& compiler
}

%locations

%define parse.trace

%define parse.error verbose

%code {
    #include "include/compiler.hh"
    #include "include/ast.hh"
}

%define api.token.prefix {TOK_}

%token END 0 "end of file";

%token <std::string> INTEGER

%printer {
    yyo << $$;
} <*>;

%%

%start EXPRESSION;

EXPRESSION : INTEGER
           ;

%%

void yy::parser::error(const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
