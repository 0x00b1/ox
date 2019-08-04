%{ /* -*- C++ -*- */
    # include <cerrno>
    # include <climits>
    # include <cstdlib>
    # include <cstring> // strerror
    # include <string>

    # include "compiler.hh"
    # include "parser.hh"
%}

%{
    // Work around an incompatibility in flex (at least versions 2.5.31 through
    // 2.5.33): it generates code that does not conform to C89.  See Debian bug
    // 333231 <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.
    # undef yywrap
    # define yywrap() 1

    // Pacify warnings in yy_init_buffer (observed with Flex 2.6.4)
    // and GCC 6.4.0, 7.3.0.
    #if defined __GNUC__ && !defined __clang__ && 6 <= __GNUC__
    # pragma GCC diagnostic ignored "-Wnull-dereference"
    #endif

    // Of course, when compiling C as C++, expect warnings about NULL.
    #if defined __clang__
    # pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
    #elif defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
    # pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"
    #endif

    #define FLEX_VERSION (YY_FLEX_MAJOR_VERSION * 100 + YY_FLEX_MINOR_VERSION)

    // Old versions of Flex (2.5.35) generate an incomplete documentation comment.
    //
    //  In file included from src/scan-code-c.c:3:
    //  src/scan-code.c:2198:21: error: empty paragraph passed to '@param' command
    //        [-Werror,-Wdocumentation]
    //   * @param line_number
    //     ~~~~~~~~~~~~~~~~~^
    //  1 error generated.
    #if FLEX_VERSION < 206 && defined __clang__
    # pragma clang diagnostic ignored "-Wdocumentation"
    #endif

    // Old versions of Flex (2.5.35) use 'register'.  Warnings introduced in
    // GCC 7 and Clang 6.
    #if FLEX_VERSION < 206
    # if defined __clang__ && 6 <= __clang_major__
    #  pragma clang diagnostic ignored "-Wdeprecated-register"
    # elif defined __GNUC__ && 7 <= __GNUC__
    #  pragma GCC diagnostic ignored "-Wregister"
    # endif
    #endif

    #if FLEX_VERSION < 206
    # if defined __clang__
    #  pragma clang diagnostic ignored "-Wconversion"
    #  pragma clang diagnostic ignored "-Wdocumentation"
    #  pragma clang diagnostic ignored "-Wshorten-64-to-32"
    #  pragma clang diagnostic ignored "-Wsign-conversion"
    # elif defined __GNUC__
    #  pragma GCC diagnostic ignored "-Wconversion"
    #  pragma GCC diagnostic ignored "-Wsign-conversion"
    # endif
    #endif
%}

%option noyywrap nounput noinput batch debug

FLOATING_POINT  [0-9]*\.[0-9]+
IDENTIFIER      [a-zA-Z][a-zA-Z_0-9]*
INTEGER         [0-9]*
WHITESPACE      [ \t]

%{
  // Code run each time a pattern is matched.
  #define YY_USER_ACTION location.columns(yyleng);
%}

%x IN_COMMENT

%%

%{
  // A handy shortcut to the location held by the Compiler.
  yy::location& location = compiler.location;

  // Code run each time yylex is called.
  location.step();
%}

{WHITESPACE}+ {
  location.step();
}

\n+ {
  location.lines(yyleng);

  location.step();
}

 "8-bit"          return yy::parser::make_KEYWORD__8_BIT(location);
"16-bit"          return yy::parser::make_KEYWORD_16_BIT(location);
"32-bit"          return yy::parser::make_KEYWORD_32_BIT(location);
"64-bit"          return yy::parser::make_KEYWORD_64_BIT(location);
"as"              return yy::parser::make_KEYWORD_AS(location);
"Boolean"         return yy::parser::make_KEYWORD_BOOLEAN(location);
"constant"        return yy::parser::make_KEYWORD_CONSTANT(location);
"else"            return yy::parser::make_KEYWORD_ELSE(location);
"False"           return yy::parser::make_KEYWORD_FALSE(location);
"Floating-point"  return yy::parser::make_KEYWORD_FLOATING_POINT(location);
"if"              return yy::parser::make_KEYWORD_IF(location);
"Integer"         return yy::parser::make_KEYWORD_INTEGER(location);
"is"              return yy::parser::make_KEYWORD_IS(location);
"reference"       return yy::parser::make_KEYWORD_REFERENCE(location);
"return"          return yy::parser::make_KEYWORD_RETURN(location);
"shared"          return yy::parser::make_KEYWORD_SHARED(location);
"Size"            return yy::parser::make_KEYWORD_SIZE(location);
"subroutine"      return yy::parser::make_KEYWORD_SUBROUTINE(location);
"True"            return yy::parser::make_KEYWORD_TRUE(location);
"unsigned"        return yy::parser::make_KEYWORD_UNSIGNED(location);

{FLOATING_POINT}  return yy::parser::make_LITERAL_FLOATING_POINT(yytext, location);
{INTEGER}         return yy::parser::make_LITERAL_INTEGER(yytext, location);

","               return yy::parser::make_PUNCTUATION_COMMA(location);
";"               return yy::parser::make_PUNCTUATION_SEMICOLON(location);
":"               return yy::parser::make_PUNCTUATION_COLON(location);
"("               return yy::parser::make_PUNCTUATION_LEFT_PARENTHESIS(location);
")"               return yy::parser::make_PUNCTUATION_RIGHT_PARENTHESIS(location);
"["               return yy::parser::make_PUNCTUATION_LEFT_SQUARE_BRACKET(location);
"]"               return yy::parser::make_PUNCTUATION_RIGHT_SQUARE_BRACKET(location);
"{"               return yy::parser::make_PUNCTUATION_LEFT_CURLY_BRACKET(location);
"}"               return yy::parser::make_PUNCTUATION_RIGHT_CURLY_BRACKET(location);
"←"               return yy::parser::make_PUNCTUATION_LEFTWARDS_ARROW(location);
"→"               return yy::parser::make_PUNCTUATION_RIGHTWARDS_ARROW(location);
"+"               return yy::parser::make_PUNCTUATION_PLUS_SIGN(location);
"÷"               return yy::parser::make_PUNCTUATION_DIVISION_SIGN(location);
"×"               return yy::parser::make_PUNCTUATION_MULTIPLICATION_SIGN(location);
"<"               return yy::parser::make_PUNCTUATION_LESS_THAN_SIGN(location);
">"               return yy::parser::make_PUNCTUATION_GREATER_THAN_SIGN(location);
"−"               return yy::parser::make_PUNCTUATION_MINUS_SIGN(location);
"≤"               return yy::parser::make_PUNCTUATION_LESS_THAN_OR_EQUAL_TO(location);
"s"               return yy::parser::make_PUNCTUATION_GREATER_THAN_OR_EQUAL_TO(location);

{IDENTIFIER}      return yy::parser::make_IDENTIFIER(yytext, location);

. {
  throw yy::parser::syntax_error(location, "invalid character: " + std::string(yytext));
}

<<EOF>> {
  return yy::parser::make_END(location);
}

%%

void Compiler::scan_begin () {
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      std::cerr << "cannot open " << file << ": " << strerror(errno) << '\n';
      exit (EXIT_FAILURE);
    }
}

void Compiler::scan_end () {
  fclose(yyin);
}
