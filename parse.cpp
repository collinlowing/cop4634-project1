// Authors: Charles Travis, Collin Lowing

#define _CRT_SECURE_NO_WARNINGS
#include "parse.hpp"

// Defualt constructor, initializes commandline with empty strring
Parse::Parse()
{
   this->debug = false;
   this->param = NULL;
   this->convertString = NULL;
}

// Parameterized constructor, assignes command argument string to commandline
// and assigns debug as true or false depending on the command line argument during program run
bool Parse::doParse(std::string command, bool debug)
{
   this->debug = debug;
   this->param = new Param; // creates a Param object on the heap
   this->convertString = new char[command.length() + 1]; // initializes a character array on the heap
   
   strcpy(convertString, command.c_str()); // copies commandline string into convertString character array
   
   return parseCommandline(); // calls parseCommandline to parse commandline string
}

bool Parse::setOutputRedirect(char *token)
{
	// prints a warning to the user if the inputRedirect is a null character and does not proceed to parse command arguments
         if (token[1] == '\0')
         {
            std::cout << "!!!Warning: the < operator must have a connecting file name!!!" << std::endl;

            
            return false;
         }

         // passes inputRedirect into Param object for storage
         param->setoutputRedirect(&token[1]);
		 
		 return true;
}

bool Parse::setInputRedirect(char *token)
{
	if (token[0] == '<')
      {
        // prints a warning to the user if the outputRedirect is a null character and does not proceed to parse command arguments
         if (token[1] == '\0')
         {
            std::cout << "!!!Warning: the > operator must have a connecting file name. Aborting commandline!!!" << std::endl;

            return false;
         }

         // passes outputRedirect into Param object for storage
         param->setoutputRedirect(&token[1]);
      }
	  
	return true;
}

bool Parse::setArgument (char *token)
{


	++counter; // adds 1 to argument count

	// checks if argument count exceeds maximum of 32 arguments
	if (counter > MAXARGS)
	{
	   std::cout << "!!!Warning this system command line overload. They system can only handle 32 arguments!!!" << std::endl;

	   return false;
	}

	// passes parsed arguments to Param object
	param->setargumentVector(token);
	param->setargumentCount(counter);
	
	return true;

}

// Parses commandline
bool Parse::parseCommandline()
{
   
   char* token;

   token = strtok(convertString, " "); // delimenates convertString by white space

   // While loop that continues until convertString has eneded
   while (token != nullptr)
   {
     // checkes for inputRedirect argument
	  switch (token[0]) {
		  case '>' : if (!setOutputRedirect(token)) return false; break;
		  case '<' : if (!setInputRedirect(token)) return false; break;
		  default : if (!setArgument(token)) return false; 
	  }
       
      // closes strtok buffer
      token = strtok(nullptr, " ");
   }

   // while in debug mode, prints out a list of arguments and redirects
   if(debug)
     param->printParams();
 
	return true;
}
