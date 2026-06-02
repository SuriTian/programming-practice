/**
 * You are given a string s consisting of only uppercase english characters and an integer k.
 * You can choose up to k characters of the string and replace them with any other uppercase English character.
 * After performing at most k replacements, return the length of the longest substring which contains only one distinct character.
 */

#include <string>
#include <unordered_set>
#include <algorithm> 
using namespace std;

int characterReplacement(string s, int k) {
    // number of replacements = length of the current substring - frequency of the most frequent character

    int maxLen = 0;
    unordered_set<char> charSet(s.begin(), s.end());

    for (char c : charSet) {
        int l = 0, count = 0; 

        // sliding window
        for (int r = 0; r < s.size(); r++) {
            // each substring
            if (s[r] == c) {
                count++; 
            }

            // when k is not enough number of replacement, make the window smaller and update count 
            while (r - l + 1 - count > k) {
                if (s[l] == c) {
                    count--; 
                }

                l++;
            }

            maxLen = max(maxLen, r - l + 1); // pick the larger window size
        }
    }

    return maxLen;
}