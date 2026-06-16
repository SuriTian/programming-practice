#include <string>
#include <stack>
#include <string>
#include <vector> 

using namespace std; 

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> resStack; 

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num1 = stoi(resStack.top());
                resStack.pop();
                int num2 = stoi(resStack.top());
                resStack.pop();

                if (tokens[i] == "+") {
                    resStack.push(to_string(num2 + num1));
                }
                else if (tokens[i] == "-") {
                    resStack.push(to_string(num2 - num1));
                }
                else if (tokens[i] == "*") {
                    resStack.push(to_string(num2 * num1));
                }
                else {
                    resStack.push(to_string(num2 / num1)); 
                }
            }
            else {
                resStack.push(tokens[i]);
            }
        }

        return stoi(resStack.top());
    } 
};