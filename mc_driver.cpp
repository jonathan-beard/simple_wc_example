#include <cctype>
#include <fstream>

#include "mc_driver.hpp"

#ifndef FAIL
#define FAIL -1
#endif

MC::MC_Driver::~MC_Driver(){ 
   if( scanner != (MC::MC_Scanner*)NULL) delete(scanner); 
   if( parser  != (MC::MC_Parser*)NULL) delete(parser);
}

void MC::MC_Driver::parse( const char *filename ){
   std::ifstream in_file( filename );
   if( ! in_file.good() ) exit( EXIT_FAILURE );
   scanner = new MC::MC_Scanner( &in_file );
   /* check to see if its initialized */
   if( scanner == (MC::MC_Scanner*) NULL){
      std::cerr << "Failed to init scanner!!\n";
   }
   parser = new MC::MC_Parser( (*scanner) /* scanner */, 
                               (*this) /* driver */ );
   
   if(parser->parse() == FAIL){
      std::cerr << "Parse failed!!\n";
   }
}

void MC::MC_Driver::add_upper(){ uppercase++; chars++; words++; }

void MC::MC_Driver::add_lower(){ lowercase++; chars++; words++; }

void MC::MC_Driver::add_word(std::string *c){
   words++; 
   chars += c->length();
   for(auto it(c->begin()); it != c->end(); ++it){
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
