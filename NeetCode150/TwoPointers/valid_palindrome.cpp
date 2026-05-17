/**
 * Given a string s, return true if it is a palindrome, otherwise return false.
 * A palindrome is a string that reads the same forward and backward. 
 * It is also case-insensitive and ignores all non-alphanumeric characters.
 * Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).
 */

#include<string>
#include <cctype>


using namespace std; 

bool isPalindrome(string s) {
    int frontIdx = 0; 
    int backIdx = s.size() - 1; 

    while (frontIdx < backIdx) {
        if (isalnum(s.at(frontIdx)) && isalnum(s.at(backIdx))) {
            if (tolower(s.at(frontIdx)) != tolower(s.at(backIdx))) {
                return false; 
            }

            frontIdx++;
            backIdx--; 
        }
        else {
            if (!isalnum(s.at(frontIdx))) {
                frontIdx++;
            }
            if (!isalnum(s.at(backIdx))) {
                backIdx--;
            }
        }
    }

    return true;
}