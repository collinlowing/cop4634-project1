
#include "parse.hpp"
Parse::~Parse()
{
   delete convertString;
   for(int i = 0; i < setParam->getargumentCount(); i++)
   {
   delete setParam->getargumentVector();
   }
   delete setParam;
}

Parse::Parse()
{
   commandline = "";
}

Parse::Parse(std::string command, bool debug)
{
   commandline = command;
   this->debug = debug;
   setParam = new Param;
   parseCommandline();
}

void Parse::parseCommandline()
{
   this->convertString = new char[commandline.length() + 1];
   strcpy(convertString, commandline.c_str());

   convertString = strtok(convertString, " ");
   while (convertString != nullptr)
   {
      if (convertString[0] == '<')
      {
         if (convertString[1] == '\0')
         {
            std::cout << "!!!Warning: the < operator must have a connecting file name!!!" << std::endl;
            return;
         }
         setParam->setinputRedirect(&convertString[1]);
      }
      else if (convertString[0] == '>')
      {
         if (convertString[1] == '\0')
         {
            std::cout << "!!!Warning: the > operator must have a connecting file name. Aborting commandline!!!" << std::endl;
            return;
         }
         setParam->setoutputRedirect(&convertString[1]);
      }
      else
      {

        ++counter;

        if (counter > MAXARGS)
        {
           std::cout << "!!!Warning this system command line overload. They system can only handle 32 arguments!!!" << std::endl;
           return;
        }
        setParam->setargumentVector(convertString);
        setParam->setargumentCount(counter);

      }
      convertString = strtok(nullptr, " ");
   }
  
   if(debug)
     setParam->printParams();
}
