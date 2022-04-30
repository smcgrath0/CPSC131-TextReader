#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "sanitize.hpp"

using namespace std;

class TextReader {

private:

    map<string, vector<string>> wordFollowers;

public:
    
    void readIn(const string & filename);

    bool isEndPunctuation(const char & character);

    vector<string> getValues(const string & key);

    bool search(const string& key);

    size_t howManyfollowers(const string& key);
    
};

//  TO DO

//  COMPLETE THE FOLLOWING FUNCTIONS


void TextReader::readIn(const string& filename) {




}


bool TextReader::isEndPunctuation(const char& character) {



}



vector<string> TextReader::getValues(const string& key) {




}



bool TextReader::search(const string& key) {



}


size_t TextReader::howManyfollowers(const string& key) {




}