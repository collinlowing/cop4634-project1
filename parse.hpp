
#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <string>
#include <cstring>

#include "param.hpp"




class Parse
{
private:
   Param * setParam;
   std::string commandline;
   void parseCommandline();
   int counter = 0;
   bool debug = false;
public:
   Parse();
   Parse(std::string command, bool debug);
   ~Parse() { /* delete[] setParam; */}
   void setDebug(bool debug) { this->debug = debug; }


};

#endif
