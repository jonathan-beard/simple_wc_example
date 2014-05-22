%{
/* C++ string header, for string ops below */
#include <string>

/* Implementation of yyFlexScanner */ 
#include "mc_scanner.hpp"
#undef  YY_DECL
#define YY_DECL int MC::MC_Scanner::yylex(MC::MC_Parser::semantic_type *lval)

/* typedef to make the returns for the tokens shorter */
typedef MC::MC_Parser::token token;

/* define to keep from re-typing the same code over and over */
#define STOKEN( x ) ( new std::string( x ) )

/* define yyterminate as this instead of NULL */
#define yyterminate() return( token::END )

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

%}

%option debug 
%option nodefault 
%option yyclass="MC::MC_Scanner" 
%option noyywrap 
%option c++

%%
%{          // Code executed at the beginning of yylex
            yylval = lval;
%}

[a-z]       { 
               return( token::LOWER );     
            }

[A-Z]       { 
               return( token::UPPER );     
            }

[a-zA-Z]+   { 
               yylval->sval = STOKEN( yytext );  
               return( token::WORD );      
            }

\n          { 
               return( token::NEWLINE );   
            }

.           { 
               return( token::CHAR );      
            }
%%


