#ifndef __MCDRIVER_HPP__
#define __MCDRIVER_HPP__ 1

#include <string>
#include <cstdint>
#include "mc_scanner.hpp"
#include "mc_parser.tab.hh"

namespace MC{

class MC_Driver{
public:
   MC_Driver() = default;

   virtual ~MC_Driver();

   void parse( const char *filename );
  

   void add_upper();
   void add_lower();
   void add_word( const std::string &word );
   void add_newline();
   void add_char();

   std::ostream& print(std::ostream &stream);
private:
   int chars      = 0;
   int words      = 0;
   int lines      = 0;
   int uppercase  = 0;
   int lowercase  = 0;
   MC::MC_Parser  *parser  = nullptr;
   MC::MC_Scanner *scanner = nullptr;
};

} /* end namespace MC */
#endif /* END __MCDRIVER_HPP__ */
