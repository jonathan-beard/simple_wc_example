#ifndef __MCDRIVER_HPP__
#define __MCDRIVER_HPP__ 1

#include <string>
#include "mc_scanner.hpp"
#include "mc_Parser.tab.hh"

namespace MC{

class MC_Driver{
public:
   MC_Driver() : chars(0),
                 words(0),
                 lines(0),
                 uppercase(0),
                 lowercase(0),
                 parser( nullptr ),
                 scanner( nullptr ){};

   virtual ~MC_Driver();

   void parse( const char *filename );
  

   void add_upper();
   void add_lower();
   void add_word( const std::string &c );
   void add_newline();
   void add_char();

   std::ostream& print(std::ostream &stream);
private:
   int chars;
   int words;
   int lines;
   int uppercase;
   int lowercase;
   MC::MC_Parser *parser;
   MC::MC_Scanner *scanner;
};

} /* end namespace MC */
#endif /* END __MCDRIVER_HPP__ */
