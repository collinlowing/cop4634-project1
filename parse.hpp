#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <sstream>

#define MAXARGS 32

class Parse
{
private:
  char* inputRedirect;
  char* outputRedirect;
  char* argumentVector[MAXARGS];
  int   argumentCount;
public:
  void printParams();
};

#endif
