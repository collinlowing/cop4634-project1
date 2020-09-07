#include "parse.hpp"

void start(int argc, char* argv)
{
  std::cout << "Welcome to MyShell!" << std::endl << std::endl;

  //while(continue)
  //{
    Parse Param(int argc, char* argv); // Passes commandline arguements to Parse parameratized constructor
    // return parsed argurments
    std::cout << "$$$ "; // New commandline
    // read in new commands
    // parse commands
    //execute commands [part2]
  //}
}

int main() // Accepts character array commandline arguements
{
  int argc = 1;
  char* argv = "-Debug";
  start(argc, argv);
/*
  if(argc > 0)
    start(argc, argv, true);
  else
  {
    std::cout << "$$$ ";
    std::cin  >> argv;

    start(sizeof(argv), argv, true);
  }
*/
  return 0;
}
