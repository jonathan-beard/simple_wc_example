#include <cctype>
#include <fstream>
#include <cassert>

#include "mc_driver.hpp"

// wamckee 2013 APR 2 - Instead of testing for == FAIL below,
// we test for != ACCEPT (in which ACCEPT has a value of zero).
// When compiling on a MSVC 2010 platform using cygwin's Flex and Bison,
// we note that the return value from parse() is not -1 but rather +1.
// It is more likely that on different platforms the return value of zero
// will be used consistantly to indicate an accept state. Whereas, the
// value of the abort or fail state will be more likely not to be a specific
// value but rather a value that is not equal to zero.

#ifndef ACCEPT
#define ACCEPT 0
#endif

MC::MC_Driver::~MC_Driver(){ 
   delete(scanner);  // wamckee 2013 APR 2
   delete(parser);   // wamckee 2013 APR 2
}

void MC::MC_Driver::parse( const char *filename ){
   assert( filename != nullptr );
   std::ifstream in_file( filename );
   if( ! in_file.good() ) exit( EXIT_FAILURE );
   
   delete(scanner); // wamckee 2013 APR 2
   scanner = new MC::MC_Scanner( &in_file );
   /* check to see if its initialized */
   assert( scanner != nullptr );
   
   delete(parser); // wamckee 2013 APR 2
   parser = new MC::MC_Parser( (*scanner) /* scanner */, 
                               (*this) /* driver */ );
   assert( parser != nullptr );
   
   if(parser->parse() != ACCEPT) // wamckee 2013 APR 2
   {
      std::cerr << "Parse failed!!\n";
   }
}

void MC::MC_Driver::add_upper(){ uppercase++; chars++; words++; }

void MC::MC_Driver::add_lower(){ lowercase++; chars++; words++; }

void MC::MC_Driver::add_word( const std::string &c ){
   words++; 
   chars += c.length();
   for(auto it(c.begin()); it != c.end(); ++it){
      if( islower( (*it) ) ) { lowercase++; }
      else if ( isupper( (*it) ) ) { uppercase++; }
   }
}

void MC::MC_Driver::add_newline(){ lines++; chars++; }

void MC::MC_Driver::add_char(){ chars++; }


std::ostream& MC::MC_Driver::print(std::ostream &stream){
   stream << "Uppercase: " << uppercase << "\n";
   stream << "Lowercase: " << lowercase << "\n";
   stream << "Lines: " << lines << "\n";
   stream << "Words: " << words << "\n";
   stream << "Characters: " << chars << "\n";
   return(stream);
}
