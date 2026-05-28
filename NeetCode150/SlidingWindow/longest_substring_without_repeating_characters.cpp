/**
 * Given a string s, find the length of the longest substring without duplicate characters.
 * A substring is a contiguous sequence of characters within a string.
 */

#include <string> 
#include <unordered_set> 
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> hashSet; 

    int l = 0;
    int maxLen = 0; 

    for (int r = 0; r < s.length(); r++) {
        while (hashSet.find(s.at(r)) != hashSet.end()) {
            // see a duplicate
            hashSet.erase(s.at(r)); 
            l++; 
        }
        hashSet.insert(s.at(l)); // move l 
        maxLen = max(maxLen, r - l + 1);
    }
    
    return maxLen;
}