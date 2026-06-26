#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1; 
        int rowLen = matrix.at(0).size(); 

        while (l <= r) {
            int m = (r - l) / 2 + l; 
            if (matrix[m].at(0) <= target && matrix[m].at(rowLen - 1) >= target) {
                // binary search here
                int l2 = 0;
                int r2 = rowLen - 1;

                while (l2 <= r2) {
                    int m2 = (r2 - l2) / 2 + l2;
                    
                    if (matrix[m].at(m2) == target) {
                        return true;
                    }
                    else if (matrix[m].at(m2) > target) {
                        r2 = m2 - 1;
                    }
                    else {
                        l2 = m2 + 1;
                    }
                }

                return false;
            }
            else if (matrix[m].at(0) > target) {
                r = m - 1; 
            }
            else {
                l = m + 1;
            }
        }

        return false; 
    }
};
