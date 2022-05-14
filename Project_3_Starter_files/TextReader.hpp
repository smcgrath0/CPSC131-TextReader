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

    ifstream myReadFile;
    myReadFile.open(filename);
    char output[100];
    string oldWord = "^";
    string newWord;

    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {

            myReadFile >> newWord;

            sanitize(newWord);

            std::map<string,vector<string>>::iterator it = wordFollowers.find(oldWord);

            if (isEndPunctuation(newWord[newWord.length() - 1])) {
              	string punc = std::string(1, newWord[newWord.length() - 1]);
                string firstpart = newWord.substr(0, ( newWord.length() - 1 ));

                std::map<string,vector<string>>::iterator itpunc = wordFollowers.find(oldWord);

                std::vector<string>::iterator it3;

                if (itpunc != wordFollowers.end()) {

                        itpunc->second.push_back(firstpart);                
                } else {
                    wordFollowers.insert(std::pair<string,vector<string>>(oldWord,{firstpart}));
                }

                itpunc = wordFollowers.find(firstpart);
                if (itpunc != wordFollowers.end()) {
                    itpunc->second.push_back(punc);
                } else {
                    wordFollowers.insert(std::pair<string,vector<string>>(firstpart,{punc}));
                }

                itpunc = wordFollowers.find(punc);
                if (itpunc != wordFollowers.end()) {
                    itpunc->second.push_back("$");
                } else {
                    wordFollowers.insert(std::pair<string,vector<string>>(punc,{"$"}));
                }

                oldWord = "^";

            } else if (it != wordFollowers.end()) {

                it->second.push_back(newWord);
                oldWord = newWord;  

            } else {
                
                std::vector<string> vec = {};
                wordFollowers.insert(std::pair<string,vector<string>>(oldWord,{newWord}));
                oldWord = newWord;  
                
            }
        }
    }
    myReadFile.close();
}


bool TextReader::isEndPunctuation(const char& character) {
    if (character == '.' || character == '?' || character == '!')
        return true;
    return false;
}



vector<string> TextReader::getValues(const string& key) {
    std::vector<string> vec = {};
    std::map<string,vector<string>>::iterator it = wordFollowers.find(key);
    if (it != wordFollowers.end())
       return it->second;
    return vec;
}



bool TextReader::search(const string& key) {
    std::map<string,vector<string>>::iterator it = wordFollowers.find(key);
    if (it != wordFollowers.end())
       return true;
    return false;
}


size_t TextReader::howManyfollowers(const string& key) {
    size_t a = 0;
    std::map<string,vector<string>>::iterator it = wordFollowers.find(key);
    if (it != wordFollowers.end())
       return it->second.size();
    return a;
}