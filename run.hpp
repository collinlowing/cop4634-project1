#ifndef RUN_HPP
#define RUN_HPP

#include <iostream>
#include <sstream>
#include <string>

class Run
{
private:

public:
  friend std::ostream& operator<<(std::ostream& os, const Run& r);
};

#endif
