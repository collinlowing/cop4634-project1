
#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>

#include <string>

#include "param.hpp"




class Parse
{
private:
   Param * setParam;
   std::string commandline;
   void parseCommandline();
public:
   Parse();
   Parse(std::string command);
   ~Parse() { /*std::cout << "deleted" << std::endl;*/ };
   

};

#endif