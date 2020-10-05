// Authors: Charles Travis, Collin Lowing

#include "param.hpp"
#include <iostream>

// Defualt constructor that initializes private class variables
Param::Param()
{
   argumentCount = 0;

   inputRedirect = nullptr;

   outputRedirect = nullptr;
}

// Prints debug message for testing
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

// sets private variable inputRedirect
void Param::setinputRedirect(char *inputRedirect)
{
   this->inputRedirect = inputRedirect;
}

// sets private variable outputRedirect
void Param::setoutputRedirect(char * outputRedirect)
{
   this->outputRedirect = outputRedirect;
}

// sets private variable argumentCount
void Param::setargumentCount(int counter)
{
   this->argumentCount = counter;
}

// sets private variable argumentVector
void Param::setargumentVector(char * argumentVector)
{
   this->argumentVector[argumentCount] = argumentVector;
}

// returns private variable argumentCount
int Param::getargumentCount()
{
   return this->argumentCount;
}

// returns private character array argumentVector
char* Param::getargumentVector()
{
	return argumentVector[argumentCount];
}
