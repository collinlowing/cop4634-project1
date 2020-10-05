// Authors: Charles Travis, Collin Lowing

#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <string>
#include <cstring>

#include "param.hpp"




class Parse
{
private:
   Param*      param;
   char*       convertString;
   int         counter = 0;
   
   bool        debug = false;
   
   bool setOutputRedirect(char *token);
   bool setInputRedirect (char *token);
   bool setArgument (char *token);

   bool parseCommandline();
   
   
 
public:
   Parse();
   //Parse(std::string command, bool debug);
   ~Parse() {  delete[] param; delete[] convertString; }
   
   bool doParse(std::string command, bool debug);
   
   void setDebug(bool debug) { this->debug = debug; }


};

#endif
