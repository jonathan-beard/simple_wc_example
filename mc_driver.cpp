#include <cctype>
#include <fstream>
#include <cassert>

#include "mc_driver.hpp"

MC::MC_Driver::~MC_Driver(){ 
   delete(scanner);
   delete(parser);
}

void 
MC::MC_Driver::parse( const char *filename )
{
   assert( filename != nullptr );
   std::ifstream in_file( filename );
   if( ! in_file.good() ) exit( EXIT_FAILURE );
   
   delete(scanner);
   scanner = nullptr;
   scanner = new MC::MC_Scanner( &in_file );
   /* check to see if its initialized */
   assert( scanner != nullptr );
   
   delete(parser); 
   parser = nullptr;
   parser = new MC::MC_Parser( (*scanner) /* scanner */, 
                               (*this) /* driver */ );
   assert( parser != nullptr );
   
   const int accept( 0 );
   if( parser->parse() != accept )
   {
      std::cerr << "Parse failed!!\n";
   }
}

void 
MC::MC_Driver::add_upper()
{ 
   uppercase++; 
   chars++; 
   words++; 
}

void 
MC::MC_Driver::add_lower()
{ 
   lowercase++; 
   chars++; 
   words++; 
}

void 
MC::MC_Driver::add_word( const std::string &c )
{
   words++; 
   chars += c.length();
   for(auto it(c.begin()); it != c.end(); ++it){
      if( islower( (*it) ) )
      { 
         lowercase++; 
      }
      else if ( isupper( (*it) ) ) 
      { 
         uppercase++; 
      }
   }
}

void 
MC::MC_Driver::add_newline()
{ 
   lines++; 
   chars++; 
}

void 
MC::MC_Driver::add_char()
{ 
   chars++; 
}


std::ostream& 
MC::MC_Driver::print( std::ostream &stream )
{
   stream << "Uppercase: " << uppercase << "\n";
   stream << "Lowercase: " << lowercase << "\n";
   stream << "Lines: " << lines << "\n";
   stream << "Words: " << words << "\n";
   stream << "Characters: " << chars << "\n";
   return(stream);
}
