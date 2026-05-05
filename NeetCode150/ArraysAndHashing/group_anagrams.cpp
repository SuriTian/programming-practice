/**
 * Given an array of strings strs, group all anagrams together into sublists. 
 * You may return the output in any order.
 * An anagram is a string that contains the exact same characters as another string, 
 * but the order of the characters can be different.
 */


#include<vector>
#include<string> 
#include <map>

using namespace std; 

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<vector<int>, vector<string>> allAnagrams; 
    vector<vector<string>> result;

    for (int i = 0; i < strs.size(); i++) {
        vector<int> alphabetList(26); 
        for (int j = 0; j < strs.at(i).size(); j++) {
            alphabetList.at(strs.at(i).at(j)%97)++;
        }

        if (allAnagrams.find(alphabetList) != allAnagrams.end()) {
            allAnagrams[alphabetList].push_back(strs.at(i)); 
        }
        else {
            vector<string> temp;
            temp.push_back(strs.at(i));
            allAnagrams[alphabetList] = temp;  
        }
    }

    for (auto & pair : allAnagrams) {
        result.push_back(pair.second);
    }

    return result;
}