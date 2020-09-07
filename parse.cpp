#include "parse.hpp"

Parse::Parse()
{
  print();
}

std::string Parse::print()
{
  testStr = "This is a test";
  return testStr;
}

std::ostream& operator<<(std::ostream& os, const Parse& p)
{
	os << p.testStr;

  return os;
}
