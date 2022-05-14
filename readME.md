**Project 3: Text Reader**
CPSC 131 Spring 2022

The main idea is to break sentences into words and store every word with all of its following words in a data structure.

Complete the implementation of this class, adding public/private member variables and functions as needed. Your code is tested in the provided main.cpp.

You will need to implement the following functions:

bool isEndPunctuation(char) - This should return true if the given char is one of the following: . ? !
void readIn(const string &) - See hints.
vector<string> getValues(const string &) - See hints.
bool search(const string &) - See hints.
size_t howManyfollowers(const string &) - See hints.

--- 

**Results:** 

-PASSED '.' is Punctuation :: expected and actual '1'
-PASSED '?' is Punctuation :: expected and actual '1'
-PASSED '!' is Punctuation :: expected and actual '1'
-PASSED 'a' is Punctuation :: expected and actual '0'
-PASSED Values : Frankenstein 'youthful': expected and actual lists match: { lovers, days lovers }
-PASSED Values : Frankenstein 'marked': expected and actual lists match: { out the the by in their on }
-PASSED Value Count : Frankenstein '^' - 0: : expected and actual '1'
-PASSED Searching : Frankenstein 'rejoice' found: expected and actual '1'
-PASSED Followers Count : Frankenstein 'breeze': expected and actual '8'
-PASSED Followers Count : Frankenstein 'river': expected and actual '9'
-PASSED Values : SleepyHollow 'woody': expected and actual lists match: { hill, crests dell, }
-PASSED Values : SleepyHollow 'quarter': expected and actual lists match: { which of of }
-PASSED Value Count : SleepyHollow '^' < 0: expected and actual '0'
-PASSED Searching : SleepyHollow 'complexity' found: expected and actual '0'
-PASSED Followers Count : SleepyHollow 'complexity': expected and actual '0'
-PASSED Followers Count : SleepyHollow 'river': expected and actual '2'
-
-16 tests passed out of 16 total tests
-100/100