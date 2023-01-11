// survivor.cpp
// Implement any helper functions here. Do not modify the survivor.h file
// Your name:
// Your perm number: 
#include "survivor.h"
#include <iostream>
using namespace std;

int countVotes(Parchment *validVotes, string candidate)
{   
     if(!validVotes) return 0;
     if(validVotes->vote == candidate){
          return 1 + countVotes(validVotes->next, candidate);
     }else{
          return countVotes(validVotes->next, candidate);
     }
     
 //    return 0;
}

string votedOut(Parchment *validVotes)
{
     if(!validVotes) return "";
     string result = "";
     int maxVotes = 0;
     Parchment *t = validVotes;
     while(t){
          int num_votes = countVotes(validVotes, t->vote);
          if(num_votes > maxVotes){ 
               maxVotes = num_votes;
               result = t->vote;
               // cout << "max votes :" << maxVotes << endl;
               // cout << "Candidate to vote out: "<< result << endl; 
          }
          t = t->next;
     }
     return result;

}
// Ex1 :
// J->B->J->B->J
//    new_sublist: B->B
// Ex2:
// J->J->J->B->J
//    new_sublist: B

Parchment *tallyTheVote(Parchment *votingUrn, HiddenImmunityIdol *idolUsed)
{
     if(!votingUrn) return nullptr;
     Parchment * new_sublist = tallyTheVote(votingUrn->next, idolUsed);
     if(votingUrn->vote == idolUsed->target){
          delete votingUrn;
          return new_sublist;
     } else{
          votingUrn->next = new_sublist;
          return votingUrn;
     }
 
}