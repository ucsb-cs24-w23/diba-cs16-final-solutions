#include "survivor.h"
#include "tddFuncs.h"
#include "string.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cerr << "Usage: " << argv[0] << " [num of test to run]" << std::endl;
    return 1;
  }

  else
  {
    int testNum = atoi(argv[1]);
    Parchment *v5 = new Parchment{"Baylor", "Jaclyn", nullptr};
    Parchment *v4 = new Parchment{"Natalie", "Baylor", v5};
    Parchment *v3 = new Parchment{"Missy", "Jaclyn", v4};
    Parchment *v2 = new Parchment{"Jaclyn", "Baylor", v3};
    Parchment *v1 = new Parchment{"Keith", "Jaclyn", v2};
    Parchment *sanJuanDelSurUrn = v1;

    if (testNum == 1)
    {
      START_TEST_GROUP("COUNT_VOTES 1");
      // Test 1: Provided Example
      assertEquals(countVotes(sanJuanDelSurUrn, "Keith"), 0, "Test 1: countVotes(sanJuanDelSurUrn, \"Keith\")");
    }
    else if (testNum == 2)
    {
      START_TEST_GROUP("COUNT_VOTES 2");
      assertEquals(countVotes(sanJuanDelSurUrn, "Jaclyn"), 3, "Test 2: countVotes(sanJuanDelSurUrn, \"Jaclyn\")");
    }
    else if (testNum == 3)
    {
      START_TEST_GROUP("COUNT_VOTES 3");
      assertEquals(countVotes(sanJuanDelSurUrn, "Baylor"), 2, "Test 3");
     }
  }
  return 0;
}
