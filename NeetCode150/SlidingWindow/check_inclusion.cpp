#include <string>
#include <vector>

using namespace std; 

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false; 

        vector<int> s1Freq(26, 0); 
        vector<int> windowFreq(26, 0);

        // set up the window 
        for (int i = 0; i < s1.size(); i++) {
            s1Freq[s1[i] - 'a']++;
            windowFreq[s2[i] - 'a']++;
        }

        int matches = 0; 

        // check first window
        for (int i = 0; i < 26; i++) {
            if (s1Freq[i] == windowFreq[i]) matches++; 
        }

        // change the window to check the rest
        for (int i = s1.size(); i < s2.size(); i++) {
            if (matches == 26) return true;

            // Remove oldest character to window
            windowFreq[s2[i - s1.size()] - 'a']--;

            if (windowFreq[s2[i - s1.size()] - 'a'] == s1Freq[s2[i - s1.size()] - 'a']) matches++;
            else if (windowFreq[s2[i - s1.size()] - 'a'] + 1 == s1Freq[s2[i - s1.size()] - 'a']) matches--;
            
            // Add new character to window
            windowFreq[s2[i] - 'a']++; 
            
            if (windowFreq[s2[i] - 'a'] == s1Freq[s2[i] - 'a']) matches++;
            else if (windowFreq[s2[i] - 'a'] - 1 == s1Freq[s2[i] - 'a']) matches--; 
        }

        return matches == 26; 
    }
};
