%skeleton "lalr1.cc"
%require  "2.5"
%debug 
%defines 
%define namespace "MC"
%define parser_class_name "MC_Parser"

%code requires{
   namespace MC {
      class MC_Driver;
      class MC_Scanner;
   }
}

%lex-param   { MC_Scanner  &scanner  }
%parse-param { MC_Scanner  &scanner  }

%lex-param   { MC_Driver  &driver  }
%parse-param { MC_Driver  &driver  }

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   /* include for all driver functions */
   #include "mc_driver.hpp"
  
   /* this is silly, but I can't figure out a way around */
   static int yylex(MC::MC_Parser::semantic_type *yylval,
                    MC::MC_Scanner  &scanner,
                    MC::MC_Driver   &driver);
   
}

/* token types */
%union {
   std::string *sval;
}

%token            END    0     "end of file"
%token            UPPER
%token            LOWER
%token   <sval>   WORD
%token            NEWLINE
%token            CHAR


%destructor { delete( $$ ); } WORD


%%

list_option : END | list END;

list
  : item
  | list item
  ;

item
  : UPPER   { driver.add_upper(); }
  | LOWER   { driver.add_lower(); }
  | WORD    { driver.add_word( *$1 ); }
  | NEWLINE { driver.add_newline(); }
  | CHAR    { driver.add_char(); }
  ;

%%


void MC::MC_Parser::error( const MC::MC_Parser::location_type &l,
                           const std::string &err_message)
{
   std::cerr << "Error: " << err_message << "\n"; 
}


/* include for access to scanner.yylex */
#include "mc_scanner.hpp"
static int yylex(MC::MC_Parser::semantic_type *yylval,
                 MC::MC_Scanner  &scanner,
                 MC::MC_Driver   &driver)
{
   return( scanner.yylex(yylval) );
}

