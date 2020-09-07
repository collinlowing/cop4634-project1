#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <sstream>
#include <string>

#define MAXARGS 32

class Parse
{
private:
  //const int MAXARGS = 32;
  char *inputRedirect;  //filename for input
  char *outputRedirect; //filename for output
  int argumentCount;
  char *argumentVector[MAXARGS];
public:
  Parse(int argc, char** argv);
  std::string printParams();
  friend std::ostream& operator<<(std::ostream& os, const Parse& p);
};

#endif
