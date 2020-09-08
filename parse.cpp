#include "parse.hpp"


Parse::Parse(int argc, char** argv)
{
  Parse::argumentCount = argc;
  if(argc <= MAXARGS)
  {
    Parse::argumentVector = argv;
  }
  else
  {
    std::cout << "ERROR: arguments exceed maximum (32)";
    exit(1);
  }
}


void Parse::printParams()
{
  if (Parse::inputRedirect != nullptr)
      std::cout << "inputRedirect: [" << Parse::inputRedirect << "]" << std::endl;
  else
      std::cout << "inputRedirect: [NULL]" << std::endl;

  if (outputRedirect != nullptr)
      std::cout << "outputRedirect: [" << outputRedirect << "]" << std::endl;
  else
      std::cout << "outputRedirect: [NULL]" << std::endl;

  std::cout << "ArgumentCount: [" << Parse::argumentCount << "]" << std::endl;


  for (int i = 0; i < Parse::argumentCount; i++)
  {
    std::cout << "ArgumentVector[" << i << "]: ["
              << Parse::argumentVector[i] << "]" << std::endl;
  }

/*
  std::cout << "InputRedirect: ["
            << ((Parse::inputRedirect != NULL) ? Parse::inputRedirect : "NULL") << "]" << std::endl
            << "OutputRedirect: ["
            << (Parse::outputRedirect != NULL) ? Parse::outputRedirect : "NULL" << "]" << std::endl
            << "ArgumentCount: [" << Parse::argumentCount << "]" << std::endl;
  for (int i = 0; i < Parse::argumentCount; i++)
    std::cout << "ArgumentVector[" << i << "]: ["
              << Parse::argumentVector[i] << "]" << std::endl;
*/

}
