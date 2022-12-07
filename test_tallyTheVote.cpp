#include "survivor.h"
#include "tddFuncs.h"
#include "string.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  if(argc < 2) {
    std::cerr << "Usage: " << argv[0] << " [num of test to run]" << std::endl;
    return 1;
  } 
  
  else {
    int testNum = atoi(argv[1]);
    if (testNum == 1) {
      START_TEST_GROUP("TALLY_THE_VOTE 1");
      // Test 1: Provided Example
      Parchment* v5 = new Parchment{"Baylor", "Jaclyn", nullptr};
      Parchment* v4 = new Parchment{"Natalie", "Baylor", v5};
      Parchment* v3 = new Parchment{"Missy", "Jaclyn", v4};
      Parchment* v2 = new Parchment{"Jaclyn", "Baylor", v3};
      Parchment* v1 = new Parchment{"Keith", "Jaclyn", v2};
    
      Parchment* sanJuanDelSurUrn = v1;
      HiddenImmunityIdol* huyopa = new HiddenImmunityIdol{"Natalie", "Jaclyn"};
      Parchment* test1 = tallyTheVote(sanJuanDelSurUrn, huyopa);
      assertEquals("{Jaclyn, Baylor}->{Natalie, Baylor}", listToString(test1), "Test 1: Provided Example");
    }
    else if (testNum == 2) {
      START_TEST_GROUP("TALLY_THE_VOTE 2");
      // Test 2: General Case
      Parchment* p1 = new Parchment{"Jeremy", "Wentworth", nullptr};
      Parchment* p2 = new Parchment{"Tasha", "Wentworth", p1};
      Parchment* p3 = new Parchment{"Wentworth", "Savage", p2};
      Parchment* p4 = new Parchment{"Spencer", "Wentworth", p3};
      Parchment* p5 = new Parchment{"Ciera", "Savage", p4};
      Parchment* p6 = new Parchment{"Keith", "Wentworth", p5};
      Parchment* p7 = new Parchment{"Kimmi", "Wentworth", p6};
      Parchment* p8 = new Parchment{"Abi", "Savage", p7};
      Parchment* p9 = new Parchment{"Joe", "Wentworth", p8};
      Parchment* p10 = new Parchment{"Fishbach", "Wentworth", p9};
      Parchment* p11 = new Parchment{"Savage", "Wentworth", p10};
      Parchment* p12 = new Parchment{"Wigglesworth", "Wentworth", p11};

      Parchment* cambodiaUrn = p12;
      HiddenImmunityIdol* takeo = new HiddenImmunityIdol{"Wentworth", "Wentworth"};
      Parchment* test2 = tallyTheVote(cambodiaUrn, takeo);
      assertEquals("{Abi, Savage}->{Ciera, Savage}->{Wentworth, Savage}", listToString(test2), "Test 2: General Case");
    }
    else if (testNum == 3) {
      START_TEST_GROUP("TALLY_THE_VOTE 3");
      // Test 3: No Nullified Votes
      Parchment* d1 = new Parchment{"Natalie", "Erik", nullptr};
      Parchment* d2 = new Parchment{"Cirie", "Erik", d1};
      Parchment* d3 = new Parchment{"Amanda", "Erik", d2};
      Parchment* d4 = new Parchment{"Parvati", "Erik", d3};
      Parchment* d5 = new Parchment{"Erik", "Parvati", d4};

      Parchment* micronesiaUrn = d5;
      HiddenImmunityIdol* dabu = new HiddenImmunityIdol{"Erik", "Natalie"};
      Parchment* test3 = tallyTheVote(micronesiaUrn, dabu);
      assertEquals("{Erik, Parvati}->{Parvati, Erik}->{Amanda, Erik}->{Cirie, Erik}->{Natalie, Erik}", listToString(test3), "Test 3: No Nullified Votes");
    }
  }
  return 0;
}
