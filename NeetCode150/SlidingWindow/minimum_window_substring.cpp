#include <limits.h>
#include <map>
#include <string>

using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        map<char, int> sFreq;
        map<char, int> tFreq; 

        if (t.length() > s.length() || t.empty()) return ""; 

        // t's frequency
        for (int i = 0; i < t.length(); i++) {
            tFreq[t.at(i)]++;
        }

        int goodChar = 0;
        int needChar = tFreq.size(); 
        int l = 0; 
        int resLen = INT_MAX;
        pair<int, int> result = {-1, -1};

        // get the entire window 
        for (int r = 0; r < s.length(); r++) {
            sFreq[s.at(r)]++;

            // Only count as good character if it exists in t
            if (tFreq.count(s.at(r)) && sFreq[s.at(r)] == tFreq[s.at(r)]) goodChar++; 

            // while things are good, make left smaller 
            while (goodChar == needChar) {
                // if the new result is smaller substring than what we've currently found
                if (r - l + 1 < resLen) {
                    resLen = r - l + 1; 
                    result = {l, r};
                }

                // If moving l makes the substring disappear, update the goodChar
                sFreq[s.at(l)]--;
                if (tFreq.count(s.at(l)) && sFreq[s.at(l)] < tFreq[s.at(l)]) goodChar--;
                l++; 
            }
        }

        return resLen == INT_MAX ? "" : s.substr(result.first, resLen); 
    }
};
