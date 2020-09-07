#include "parse.hpp"

Parse::Parse(int argc, char** argv)
{
  Parse::argumentCount = argc;
  if(!Parse::argumentCount > MAXARGS)
  {
    for(int i = 0; i < argumentCount; i++)
    {
      Parse::argumentVector[i] = argv[i];

      std::cout << Parse::argumentVector[i]; // for testing
    }
  }
  else
    std::cout << "ERROR: number of arguments exceeds maximum allowed" << std::endl;
  // if -Debug then
  // printParams();
}

/*
std::string Parse::printParams() // [Given] prints out debugger
{
  std::ostringstream out;
  out <<  "InputRedirect: ["
      <<  (Parse::inputRedirect != NULL) ? Parse::inputRedirect : "NULL" << "]" << std::endl
      <<  "OutputRedirect: ["
      <<  (Parse::outputRedirect != NULL) ? Parse::outputRedirect : "NULL" << "]" << std::endl
      <<  "ArgumentCount: [" << Parse::argumentCount << "]" << std::endl;
  for (int i = 0; i < Parse::argumentCount; i++)
    out << "ArgumentVector[" << i << "]: ["
        <<  Parse::argumentVector[i] << "]" << std::endl;
}
*/

std::ostream& operator<<(std::ostream& os, const Parse& p)
{

  return os;
}
