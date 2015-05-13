#ifndef __MCSCANNER_HPP__
#define __MCSCANNER_HPP__ 1

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "mc_parser.tab.hh"

namespace MC{

class MC_Scanner : public yyFlexLexer{
public:
   
   MC_Scanner(std::istream *in) : yyFlexLexer(in),
                                  yylval( nullptr ){};
   
   int yylex(MC::MC_Parser::semantic_type * const lval)
   {
      yylval = lval;
      return( yylex() ); 
   }
   

private:
   /* hide this one from public view */
   int yylex();
   /* yyval ptr */
   MC::MC_Parser::semantic_type *yylval;
};

} /* end namespace MC */

#endif /* END __MCSCANNER_HPP__ */
