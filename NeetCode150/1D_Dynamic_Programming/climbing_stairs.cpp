class Solution {
public:
    int climbStairs(int n) {
        int stair[n + 1]; 

        for (int i = 0; i < n + 1; i++) {
            if (i == 0) {
                stair[i] = 0;
            }
            else if (i == 1) {
                stair[i] = 1;
            }
            else if (i == 2) {
                stair[i] = 2;
            }
            else {
                stair[i] = stair[i - 2] + stair[i - 1]; 
            }
        }

        return stair[n]; 
    }
};
