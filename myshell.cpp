// Collin Lowing, Charles Travis

#include "parse.hpp"
#include "param.hpp"

int main()
{
   
   std::string prompt = "user:~$ ";     //command prompt. Initialized as a variable incase we need to append to it for directory changes.
   std::string command;                 //variable where the user command line instructions are stored stored.
   

   while (1)
   {
      std::cout << prompt;
      std::getline(std::cin, command);

      //intant check for an exit call from the command string before its parsed.
      if (command == "exit")  
      {
         break;
      }

     
      Parse ParseCommands(command);
   }
   return 0;
}