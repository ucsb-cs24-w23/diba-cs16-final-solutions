//   DO NOT MODIFY THIS FILE. ADD ANY NEW HELPER FUNCTIONS IN THE FILE survivor.cpp
#ifndef SURVIVOR_H
#define SURVIVOR_H
#include <string>
using std::string;
//  ******************** BACKGROUND CONTEXT ********************
//    In Survivor, players attend Tribal Council to vote one of their competitors out of the game
//    to win the million dollar prize. Each player is given a voting **Parchment** where they
//    write down the name of a competitor they would like to vote out of the game. The **Parchment**
//    are placed in a **votingUrn** and the vote are tallied. The player with the most votes is
//    eliminated (voted out). However, there is a twist. The **HiddenImmunityIdol** is an advantage that
//    can be used on a target to nullify any votes cast against them. 

//  ******************** PARCHMENT STRUCT ********************
//    A Parchment type object contains three member variables: voter, vote, and next.
//    voter indicates which castaway casted the vote on this piece of parchment.
//    vote indicates which castaway the vote was cast against on this piece of parchment.
//    next stores a pointer to the next Parchment written and placed into the urn.
struct Parchment
{
    string voter; // name of person who casted the vote
    string vote;  // name of person the vote was cast against
    Parchment *next;
};

//  ******************** HIDDEN IMMUNITY IDOL ********************
//    An object of type HiddenImmunityIdol contains two member variables: owner and target.
//    owner indicates who the hidden immunity idol belongs to.
//    target indicates who the hidden immunity idol is played for.
struct HiddenImmunityIdol
{
    string owner;
    string target;
};
//  ********************  Problem 1 (15 pts): YOUR TASK: IMPLEMENT countVotes() ********************
//  This function takes as input:
//     validVotes: pointer to the first Parchment of valid votes at tribal council;
//               think of this as a pointer to the first element of a linked list.
//     candidate: name of the castaway to count votes for
//  The function should return:
//               the number of votes cast for candidate
//   Your implementation must be recursive to receive full credit.
//   Non-recursive implementations will receive a maximum of 10 points.
int countVotes(Parchment *validVotes, string candidate);

//  ********************  Problem 2 (10 pts): YOUR TASK: IMPLEMENT votedOut() ********************
//  This function takes as input:
//    validVotes: pointer to the first Parchment of valid votes at tribal council;
//               think of this as a pointer to the first element of a linked list.
//  The function should return:
//               the name of the person that should be voted out.
//               If there is a tie between two or more candidates, return the name of the
//               candidate that appears earlier in the list of validVotes
// Hint: Use countVotes as a helper function or write your own helper
// There is NO requirement to use recursion. Loops will work better for this problem
string votedOut(Parchment *validVotes);

//  ********************  Problem 3 (15 pts): YOUR TASK: IMPLEMENT tallyTheVote() ********************
//
//  This function takes as input:
//    votingUrn: pointer to the first Parchment cast at tribal council;
//               think of this as a pointer to the first element of a linked list;
//               you can assume these Parchments are allocated on the heap.
//    idolUsed: a hidden immunity idol that was played at tribal council;
//              any votes cast against the target of this idol do not count.

//  The function should return:
//    a pointer to the first element of a linked list of valid Parchment objects;
//    the valid votes must be in the same order as provided in the votingUrn.

//  Example: Season 29, San Jan Del Sur, Blood vs Water 2, Final 5
//    Baylor votes Jaclyn
//      p5 is Parchment object, p5.voter is Baylor, p5.vote is Jaclyn, p5.next is NULL
//    Natalie votes Baylor
//      p4 is Parchment object, p4.voter is Natalie, p4.vote is Baylor, p4.next is p5
//    Missy votes Jaclyn
//      p3 is Parchment object, p3.voter is Missy, p3.vote is Jaclyn, p3.next is p4
//    Jaclyn votes Baylor
//      p2 is Parchment object, p2.voter is Jaclyn, p2.vote is Baylor, p2.next is p3
//    Keith votes Jaclyn
//      p1 is Parchment object, p1.voter is Keith, p1.vote is Jaclyn, p1.next is p2
//    The first person to cast Keith
//      votingUrn is a Parchment pointer that points to p1
//    Natalie plays a hidden immunity idol on Jaclyn
//      hii is Parchment object, hii.owner is Natalie, hii.target is Jaclyn
//    Any votes cast for Jaclyn do not count
//      p1, p3, p5 are votes cast for Jaclyn; they are invalid.
//      p2, p4 are votes not cast for Jaclyn; they are valid.
//    Linked List Representation of Input
//      votingUrn -> p1 -> p2 -> p3 -> p4 -> p5
//    Linked List Representation of Output
//      votingUrn -> p2 -> p4
//   Your implementation must be recursive to receive full credit.
//   Non-recursive implementations will receive a maximum of 10 points.
Parchment *tallyTheVote(Parchment *votingUrn, HiddenImmunityIdol *idolUsed);

#endif // SURVIVOR_H
