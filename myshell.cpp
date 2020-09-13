// Collin Lowing, Charles Travis

#include "parse.hpp"
#include "param.hpp"


int main(int argCount, char** argArr)
{
  bool debugMode = false;
  if(argCount > 1 && (strcmp(argArr[1], "-debug") == 0 || strcmp(argArr[1], "-Debug") == 0))
    debugMode = true;

   std::string command;                   // variable where the user command line instructions are stored

   std::string prompt = "user:~$ ";       //command prompt. Initialized as a variable incase we need to append to it for directory changes.


   while (1)
   {
       std::cout << prompt;               //prints out prompt
       std::getline(std::cin, command);

      //intant check for an exit call from the command string before its parsed.
      if (command == "exit")
         break;

      Parse ArgCommands(command, debugMode);
   }

   return 0;
}
