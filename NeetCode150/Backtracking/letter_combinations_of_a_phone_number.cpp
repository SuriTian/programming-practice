#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> res; 
    vector<string> digitToString = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(string digits, string curr, int i) { // i is the current index of the string
        if (digits == "") return;
        
        if (i == digits.length()) {
            res.push_back(curr); 
            return;
        }

        dfs(digits, curr + digitToString[digits[i] - '0'][0], i + 1); 
        dfs(digits, curr + digitToString[digits[i] - '0'][1], i + 1); 
        dfs(digits, curr + digitToString[digits[i] - '0'][2], i + 1); 
 
        // four letters, have extra dfs
        if (digits[i] == '7' || digits[i] == '9') {
            dfs(digits, curr + digitToString[digits[i] - '0'][3], i + 1); 
        }
    }

    vector<string> letterCombinations(string digits) {
        dfs(digits, "", 0);
        return res;
    }
};
