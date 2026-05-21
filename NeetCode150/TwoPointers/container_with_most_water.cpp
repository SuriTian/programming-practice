/**
 * You are given an integer array heights where heights[i] represents the height of the i-th bar.
 * You may choose any two bars to form a container. 
 * Return the maximum amount of water a container can store.
 */

#include <vector>

using namespace std; 

int maxArea(vector<int>& heights) {
    int front = 0;
    int back = heights.size() - 1; 
    int maxVol = 0; 

    while (front < back) {
        int currVol = (back - front) * (heights[front] < heights[back] ? heights[front] : heights[back]); 

        maxVol = (currVol > maxVol ? currVol : maxVol);

        if (heights[front] <= heights[back]) {
            front++; 
        }
        else {
            back--;
        }
    }

    return maxVol;
}