#include<vector>
#include<string>
#include<map> 
using namespace std;

/**
 * Design an algorithm to encode a list of strings to a string. 
 * The encoded string is then sent over the network and is decoded back to the original list of strings.
 */

string encode(vector<string>& strs) {
    string result = ""; 

    for (int i = 0; i < strs.size(); i++) {
        // Wrong — appends ASCII character 0x84 for length 132
        // result += strs.at(i).length();
        result += to_string(strs.at(i).length());
        result += "#";  // delimiter used to separate length and str, cuz str could be an int
        result += strs.at(i); 
    }

    return result; 
}

vector<string> decode(string s) {
    vector<string> toDecode; 

    int curr = 0;

    while (curr < s.length()) {

        string numBuffer = "";
        while (isdigit(s.at(curr))) {
            numBuffer += s.at(curr);
            curr++;
        }

        // int len = s.at(curr); ascii of curr => wrong 

        curr++;
        int len = stoi(numBuffer); // string to int

        string buffer = "";

        for (int i = 0; i < len; i++) {
            buffer += s.at(curr); 
            curr++;
        }
        
        toDecode.push_back(buffer);
    }

    return toDecode;
}