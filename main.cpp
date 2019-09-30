#include <iostream>
#include <string>

#include "Executive.h"

int main()
{
    std::cout << "Starting...\n";
    try
   {
      Executive e1 = Executive("data.txt");
      e1.run();
   }
   catch(std::runtime_error& e)
   {
      std::cout << "Unable to open specified file. Please restart program to try again.\n";
   }
   std::cout << "\nExiting program\n";
}