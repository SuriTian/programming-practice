#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> res;

    void dfs(string curr, int open, int close, int count, int n) {
        if (open == close && count == n) {
            res.push_back(curr); 
            return;
        }
        if (count >= n || close > open) {
            return;
        }

        dfs(curr + "(", open + 1, close, count + 1, n);
        dfs(curr + ")", open, close + 1, count + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        dfs("", 0, 0, 0, n * 2);
        return res;
    }
};
