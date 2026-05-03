#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.
 * An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.
 */


bool isAnagram(string s, string t) {
    unordered_map<char, int> hashSet;
    
    for (int i = 0; i < s.length(); i++) {
        if (hashSet.find(s.at(i)) != hashSet.end()) {
            hashSet[s.at(i)]++;
        }
        else {
            hashSet.emplace(s.at(i), 1); 
        }
    }

    for (int j = 0; j < t.length(); j++) {
        if (hashSet.find(t.at(j)) != hashSet.end()) {
            hashSet[t.at(j)]--;
        }
        else {
            return false; 
        }
    }

    for (auto&pair : hashSet) {
        if (pair.second != 0) {
            return false;
        }
    }

    return true; 

}

int main () {

}