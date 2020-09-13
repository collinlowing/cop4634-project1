#include "param.hpp"
#include <iostream>

/*
Param::Param()
{
   argumentCount = 0;

   inputRedirect = nullptr;

   outputRedirect = nullptr;
}
*/
void Param::printParams()
{
   std::cout << "InputRedirect: ["
      << ((Param::inputRedirect != nullptr) ? Param::inputRedirect : "NULL") << "]" << std::endl
      << "OutputRedirect: ["
      << ((Param::outputRedirect != nullptr) ? Param::outputRedirect : "NULL") << "]" << std::endl
      << "ArgumentCount: [" << Param::argumentCount << "]" << std::endl;
   for (int i = 0; i < Param::argumentCount; i++)
      std::cout << "ArgumentVector[" << i << "]: ["
      << Param::argumentVector[i] << "]" << std::endl;
}

void Param::setinputRedirect(char *inputRedirect)
{
   this->inputRedirect = inputRedirect;
}

void Param::setoutputRedirect(char * outputRedirect)
{
   this->outputRedirect = outputRedirect;
}

void Param::setargumentCount(int counter)
{
   this->argumentCount = counter;
}

void Param::setargumentVector(char * argumentVector)
{
   this->argumentVector[argumentCount] = argumentVector;
}

int Param::getargumentCount()
{
   return this->argumentCount;
}
