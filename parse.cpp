
#define _CRT_SECURE_NO_WARNINGS
#include "parse.hpp"


Parse::Parse(std::string command)

{
   argumentCount = 0;
   inputRedirect = new char;
   inputRedirect = nullptr;
   outputRedirect = new char;
   outputRedirect = nullptr;


   char * convertString = new char[command.length() + 1];
   strcpy(convertString, command.c_str());

   convertString = strtok(convertString, " ");
   int i = 0;
   while (convertString != nullptr)         //
   {
      if (convertString[0] == '<')
      {
         if (convertString[1] == '\0')
         {
            std::cout << "!!!Warning: the < operator must have a connecting file name!!!" << std::endl;
            break;
         }
         inputRedirect = &convertString[1];
      }
      else if (convertString[0] == '>')
      {
         if (convertString[1] == ' ')
         {
            std::cout << "!!!Warning: the > operator must have a connecting file name. Aborting commandline!!!" << std::endl;
            break;
         }
         outputRedirect = &convertString[1];
      }
      else
      {
         if (argumentCount > MAXARGS)
         {
            std::cout << "!!!Warning this system command line overload. They system can only handle 35 commands at a time!!!" << std::endl;
            break;
         }
         argumentVector[i] = convertString;
         i++;
         this->argumentCount++;
      }

      convertString = strtok(nullptr, " ");         //

   }
}

void Parse::printParams()
{
     std::cout << "InputRedirect: ["
               << ((Parse::inputRedirect != nullptr) ? Parse::inputRedirect : "NULL") << "]" << std::endl
               << "OutputRedirect: ["
               << ((Parse::outputRedirect != nullptr) ? Parse::outputRedirect : "NULL") << "]" << std::endl
               << "ArgumentCount: [" << Parse::argumentCount << "]" << std::endl;
     for (int i = 0; i < Parse::argumentCount; i++)
       std::cout << "ArgumentVector[" << i << "]: ["
                 << Parse::argumentVector[i] << "]" << std::endl;
}