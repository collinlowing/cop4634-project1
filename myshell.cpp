#include "parse.hpp"


void commandHandling(char* command)
{

}

void inRedirect(std::string fileName)
{

}

void outRedirect(std::string fileName)
{
  std::fstream fileOut;
  fileOut.open(fileName, std::ios::out);

  // File IO Exception handling (if... else)
  if(fileOut)
  {
    // Creating buffers for cout, cin and file
    std::streambuf* bufferCout = std::cout.rdbuf();
    std::streambuf* bufferCin = std::cin.rdbuf();
    std::streambuf* bufferFile = fileOut.rdbuf();

    // Redirect std::cout to file
    std::cout.rdbuf(bufferFile);

    /*************For Testing******************/
      std::cout << "Testing outputRedirect()" << std::endl;
    /***************End***********************/

    // Redirect std::cout back to screen
    std::cout.rdbuf(bufferCout);

    // Closing file output stream
    fileOut.close();
  }
  else
    std::cout << "ERROR: output file redirect failed. Please try again" << std::endl;

}


int main(int argc, char** argv)
{

/*************For Testing******************/
  std::cout << "You have entered " << argc
            << " arguments:" << "\n";

  for (int i = 0; i < argc; i++)
    std::cout << argv[i] << "\n";

    // File output redirect
    //outRedirect("testOut.txt");
/***************End***********************/

  Parse Param(argc, argv);
  Param.printParams();


  return 0;
}
