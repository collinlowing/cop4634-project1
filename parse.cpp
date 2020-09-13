
#define _CRT_SECURE_NO_WARNINGS
#include "parse.hpp"

Parse::Parse()
{
   commandline = "";
}

Parse::Parse(std::string command)
{
   commandline = command;
   setParam = new Param;
   parseCommandline();
}

void Parse::parseCommandline()
{
   bool debug = false;
   int counter = 0;

   char * convertString = new char[commandline.length() + 1];
   strcpy(convertString, commandline.c_str());

   convertString = strtok(convertString, " ");
   while (convertString != nullptr)
   {
      if (convertString[0] == '<')
      {
         if (convertString[1] == '\0')
         {
            std::cout << "!!!Warning: the < operator must have a connecting file name!!!" << std::endl;
            delete[] convertString;
            return;
         }
         setParam->setinputRedirect(&convertString[1]);
      }
      else if (convertString[0] == '>')
      {
         if (convertString[1] == '\0')
         {
            std::cout << "!!!Warning: the > operator must have a connecting file name. Aborting commandline!!!" << std::endl;
            delete[] convertString;
            return;
         }
         setParam->setoutputRedirect(&convertString[1]);
      }
      else
      {
        if(strcmp(convertString, "-debug") == 0 || strcmp(convertString, "-Debug") == 0)
          debug = true;

        ++counter;

        if (counter > MAXARGS)
        {
           std::cout << "!!!Warning this system command line overload. They system can only handle 32 arguments!!!" << std::endl;
           delete[] convertString;
           return;
        }
        setParam->setargumentVector(convertString);
        setParam->setargumentCount(counter);

      }
      convertString = strtok(nullptr, " ");
   }
   delete[] convertString;


   if(debug)
     setParam->printParams();
}
