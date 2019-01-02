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

%{
  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type

  make_NUMBER(const std::string &s, const yy::parser::location_type& location);
%}

id              [a-zA-Z][a-zA-Z_0-9]*
INTEGER         [1-9][0-9]*
FLOATING_POINT  [1-9][0-9]*\.[0-9]+
blank           [ \t]

%{
  // Code run each time a pattern is matched.
  #define YY_USER_ACTION location.columns(yyleng);
%}

%%

%{
  // A handy shortcut to the location held by the Compiler.
  yy::location& location = compiler.location;

  // Code run each time yylex is called.
  location.step();
%}

"/*"((\*+[^/*])|([^*]))*\**"*/" {}

{blank}+   location.step();

\n+ {
    location.lines(yyleng);

    location.step();
}

"8-bit"           return yy::parser::make_EIGHT_BIT_KEYWORD(location);
"16-bit"          return yy::parser::make_SIXTEEN_BIT_KEYWORD(location);
"32-bit"          return yy::parser::make_THIRTY_TWO_BIT_KEYWORD(location);
"64-bit"          return yy::parser::make_SIXTY_FOUR_BIT_KEYWORD(location);

"Boolean"         return yy::parser::make_BOOLEAN_KEYWORD(location);
"Floating-point"  return yy::parser::make_FLOATING_POINT_KEYWORD(location);
"Integer"         return yy::parser::make_INTEGER_KEYWORD(location);

"as"              return yy::parser::make_AS_KEYWORD(location);
"break"           return yy::parser::make_BREAK_KEYWORD(location);
"case"            return yy::parser::make_CASE_KEYWORD(location);
"closure"         return yy::parser::make_CLOSURE_KEYWORD(location);
"constant"        return yy::parser::make_CONSTANT_KEYWORD(location);
"continue"        return yy::parser::make_CONTINUE_KEYWORD(location);
"default"         return yy::parser::make_DEFAULT_KEYWORD(location);
"else"            return yy::parser::make_ELSE_KEYWORD(location);
"enumerated"      return yy::parser::make_ENUMERATED_KEYWORD(location);
"for"             return yy::parser::make_FOR_KEYWORD(location);
"goto"            return yy::parser::make_GOTO_KEYWORD(location);
"if"              return yy::parser::make_IF_KEYWORD(location);
"immutable"       return yy::parser::make_IMMUTABLE_KEYWORD(location);
"infix"           return yy::parser::make_INFIX_KEYWORD(location);
"label"           return yy::parser::make_LABEL_KEYWORD(location);
"module"          return yy::parser::make_MODULE_KEYWORD(location);
"mutable"         return yy::parser::make_MUTABLE_KEYWORD(location);
"operator"        return yy::parser::make_OPERATOR_KEYWORD(location);
"postfix"         return yy::parser::make_POSTFIX_KEYWORD(location);
"prefix"          return yy::parser::make_PREFIX_KEYWORD(location);
"record"          return yy::parser::make_RECORD_KEYWORD(location);
"reference"       return yy::parser::make_REFERENCE_KEYWORD(location);
"return"          return yy::parser::make_RETURN_KEYWORD(location);
"subroutine"      return yy::parser::make_SUBROUTINE_KEYWORD(location);
"switch"          return yy::parser::make_SWITCH_KEYWORD(location);
"type"            return yy::parser::make_TYPE_KEYWORD(location);
"union"           return yy::parser::make_UNION_KEYWORD(location);
"unsigned"        return yy::parser::make_UNSIGNED_KEYWORD(location);
"while"           return yy::parser::make_WHILE_KEYWORD(location);

"+" return yy::parser::make_PLUS_SIGN(location);
"×" return yy::parser::make_MULTIPLICATION_SIGN(location);
"÷" return yy::parser::make_DIVISION_SIGN(location);
"−" return yy::parser::make_MINUS_SIGN(location);

"," return yy::parser::make_COMMA(location);
":" return yy::parser::make_COLON(location);
";" return yy::parser::make_SEMICOLON(location);
"…" return yy::parser::make_HORIZONTAL_ELLIPSIS(location);

"←" return yy::parser::make_LEFTWARDS_ARROW(location);
"→" return yy::parser::make_RIGHTWARDS_ARROW(location);

"λ" return yy::parser::make_GREEK_SMALL_LETTER_LAMBDA(location);

"(" return yy::parser::make_LEFT_PARENTHESIS(location);
")" return yy::parser::make_RIGHT_PARENTHESIS(location);
"[" return yy::parser::make_LEFT_SQUARE_BRACKET(location);
"]" return yy::parser::make_RIGHT_SQUARE_BRACKET(location);
"{" return yy::parser::make_LEFT_CURLY_BRACKET(location);
"}" return yy::parser::make_RIGHT_CURLY_BRACKET(location);
"⟨" return yy::parser::make_MATHEMATICAL_LEFT_ANGLE_BRACKET(location);
"⟩" return yy::parser::make_MATHEMATICAL_RIGHT_ANGLE_BRACKET(location);

"<" return yy::parser::make_LESS_THAN_SIGN(location);
"=" return yy::parser::make_EQUALS_SIGN(location);
">" return yy::parser::make_GREATER_THAN_SIGN(location);
"≠" return yy::parser::make_NOT_EQUAL_TO(location);
"≤" return yy::parser::make_LESS_THAN_OR_EQUAL_TO(location);
"≥" return yy::parser::make_GREATER_THAN_OR_EQUAL_TO(location);

"¬" return yy::parser::make_NOT_AND(location);
"∧" return yy::parser::make_LOGICAL_AND(location);
"∨" return yy::parser::make_LOGICAL_OR(location);
"⊻" return yy::parser::make_XOR(location);

{INTEGER}         return make_NUMBER(yytext, location);
{FLOATING_POINT}  return make_NUMBER(yytext, location);

{id} {
    return yy::parser::make_IDENTIFIER(yytext, location);
}

. {
    throw yy::parser::syntax_error(location, "invalid character: " + std::string(yytext));
}

<<EOF>> {
    return yy::parser::make_END(location);
}

%%

yy::parser::symbol_type make_NUMBER(const std::string &s, const yy::parser::location_type& location) {
  errno = 0;

  long n = strtol (s.c_str(), NULL, 10);

  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE)) {
    throw yy::parser::syntax_error (location, "integer is out of range: " + s);
  }

  return yy::parser::make_NUMBER ((int) n, location);
}

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
