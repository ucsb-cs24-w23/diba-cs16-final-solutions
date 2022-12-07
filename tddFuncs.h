#ifndef TDDFUNCS_H
#define TDDFUNCS_H
#include "survivor.h"

#include <string>
#include <vector>

using namespace std;

std::string listToString(Parchment *head);

void assertEquals(std::string expected, 
		  std::string actual, 
		  std::string message="");

void assertEquals(int expected, 
		  int actual, 
		  std::string message="");

void assertEquals(Parchment *expected, 
		  Parchment *actual, 
		  std::string message);

void assertEquals(Parchment **expected, 
		  int size,
		  Parchment *actual, 
		  std::string message);

#define ASSERT_EQUALS(expected,actual) assertEquals(expected,actual,#actual)


void assertTrue(bool expression, std::string message="");

#define ASSERT_TRUE(expression) assertTrue(expression,#expression)

void assertNotNull(Parchment* actual, std::string message);

#define ASSERT_NOT_NULL(actual) assertNotNull(actual,#actual)

void startTestGroup(std::string name);

#define START_TEST_GROUP(name) startTestGroup(name)

#endif // TDDFUNCS_H