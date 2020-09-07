#define CATCH_CONFIG_MAIN

#include<sstream>

#include "catch/catch.hpp"
#include "../parse.hpp"
// uncomment and add includes per your program layout
// #include "../.hpp"
// #include "../.hpp"
// #include "../.hpp"

/**************************************************
  This is a skeleton test file. You should edit
  the above includes to match header files in your
  program.
 **************************************************/

TEST_CASE("Parse Constructor")
{
  std::ostringstream parseTest;
  Parse p;
  parseTest << p;

  REQUIRE(parseTest.str() == "This is a test");
  REQUIRE(true);
}
