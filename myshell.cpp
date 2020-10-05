// Authors: Charles Travis, Collin Lowing

#include "parse.hpp"
#include "param.hpp"

// main function
// Accepts command line arguments for "-debug" flag
int main(int argCount, char** argArr)
{
  // used to printParms() if command line argument "-debug" is entered
  bool debugMode = false;
  if(argCount > 1 && (strcmp(argArr[1], "-debug") == 0 || strcmp(argArr[1], "-Debug") == 0))
    debugMode = true;

   std::string command;                   // variable where the user command line instructions are stored

   std::string prompt = "user:~$ ";       // command prompt. Initialized as a variable incase we need to append to it for directory changes.

   //while loop for
   while (1)
   {
       std::cout << prompt;               // prints out prompt e.g. user:~$
       std::getline(std::cin, command);   // accepts user input into variable command

      //intant check for an exit call from the command string before its parsed.
      if (command == "exit")
         break;

      Parse argCommands;
	  
	  argCommands.doParse(command, debugMode); // calls parameterized constructor for parsing user input command arguments
	  
	  // fork and so forth
   }

   return 0;
}
