#include <vector>

using namespace std;

class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lowK = 1;
        long hiK = 0;

        // koko only needs to eat at max the largest section in one sitting
        for (int i = 0; i < piles.size(); i++) {
            hiK = piles.at(i) > hiK ? piles.at(i) : hiK;
        }

        int res = hiK;

        while (lowK <= hiK) {
            int m = (hiK - lowK) / 2 + lowK;
            int hours = 0;

            for (int i = 0; i < piles.size(); i++) {
                hours += (piles.at(i) + m - 1) / m;
            }

            if (hours <= h) {
                res = m;
                hiK = m - 1;

            } else {
                lowK = m + 1;
            }
        }

        return res;
    }
};
