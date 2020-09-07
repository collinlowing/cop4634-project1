#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <sstream>
#include <string>

class Parse
{
private:
  std::string testStr;
public:
  Parse();
  std::string print();
  friend std::ostream& operator<<(std::ostream& os, const Parse& p);
};

#endif
