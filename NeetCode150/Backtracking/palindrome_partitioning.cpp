#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> res; 

    // not the best convention ngl would be better to use l, r
    bool isPalindrome(string& s, int i, int j) {
        while (i > j) {
            if (s[i] != s[j]) {
                return false;
            }
            j++;
            i--;
        }

        return true;
    }

    // string is [j,...,i]
    void dfs(string& s, vector<string>& curr, int i, int j) {
        if (i >= s.length()) {
            // buffer cleanup
            if (i == j) {
                res.push_back(curr);
            }

            return;
        }   

        // partition 
        if (isPalindrome(s, i, j)) {
            curr.push_back(s.substr(j, i - j + 1)); 
            dfs(s, curr, i + 1, i + 1); 
            curr.pop_back();
        }

        // don't partition 
        dfs(s, curr, i + 1, j); 
    }

    vector<vector<string>> partition(string s) {
        vector<string> curr; 
        dfs(s, curr, 0, 0);
        return res;
    }
};
