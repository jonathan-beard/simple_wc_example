#include <iostream>
#include <cstdlib>
#include <cstring>

#include "mc_driver.hpp"

int 
main( const int argc, const char **argv )
{
   /** check for the right # of arguments **/
   if( argc != 2 )
   {
      /** exit with failure condition **/
      return ( EXIT_FAILURE );
   }

   if( std::strncmp( argv[ 1 ], "-h", 2 ) == 0 )
   {
      /** simple help menu **/
      std::cout << "use -o for pipe to std::cin\n";
      std::cout << "just give a filename to count from a file\n";
      std::cout << "use -h to get this menu\n";
      return( EXIT_SUCCESS );
   }

   MC::MC_Driver driver;
   /** example for piping input from terminal, i.e., using cat **/
   if( std::strncmp( argv[ 1 ], "-o", 2 ) == 0 )
   {
      driver.parse( std::cin );
   }
   /** example reading input from a file **/
   else
   {
      /** assume file, prod code, use stat to check **/
      driver.parse( argv[1] );
   }
   driver.print( std::cout ) << "\n";

   return( EXIT_SUCCESS );
}
