/**
 * Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.
 * A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. The elements do not have to be consecutive in the original array.
 * You must write an algorithm that runs in O(n) time.
 */

#include<vector>
#include<string>
#include<map> 

using namespace std; 

int longestConsecutive(vector<int>& nums) {
    map<int, int> numNfreq; // num, frequency
    
    for (int i = 0; i < nums.size(); i++) {
        numNfreq[nums.at(i)]++; 
    }

    int largestStrSize = 0;
    int length = 0; 

    for (auto & pair: numNfreq) {
        int toCheck = pair.first - 1; 

        if (numNfreq.find(toCheck) == numNfreq.end()) {
            int nextCheck = pair.first + 1; 
            length = 1; 
            while (numNfreq.find(nextCheck) != numNfreq.end()) {
                length++; 
                nextCheck++; 
            }

            largestStrSize = (largestStrSize > length) ? largestStrSize : length; 
        }
    }

    return largestStrSize; 
}