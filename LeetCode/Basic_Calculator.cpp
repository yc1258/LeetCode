/*
 Implement a basic calculator to evaluate a simple expression string.
 
 The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
 
 You may assume that the given expression is always valid.
 
 Some examples:
 "1 + 1" = 2
 " 2-1 + 2 " = 3
 "(1+(4+5+2)-3)+(6+8)" = 23
 Note: Do not use the eval built-in library function.
*/
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate1(string s) {
        int result = 0;
        stack<int> nums,opers;
        int num = 0;
        int oper = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            else if (isdigit(s[i])){
                num = num * 10 + s[i] - '0';
            }
            else{
                result += num * oper;
                num = 0;
                if (s[i] == '+') {
                    oper = 1;
                }
                else if (s[i] == '-'){
                    oper = -1;
                }
                else if (s[i] == '('){
                    nums.push(result);
                    opers.push(oper);
                    result = 0;
                    oper = 1;
                }
                else if (s[i] == ')'){
                    result = result * opers.top() + nums.top();
                    opers.pop();
                    nums.pop();
                }
            }
        }
        result += num * oper;
        return result;
    }
    
    
    int calculate2(string s) {
        int result = 0;
        vector<int> oper (2,1);
        for (int i = 0; i< s.length(); i++) {
            if (s[i] >= '0') {
                int num = 0;
                while (i < s.length() && s[i] >= '0') {
                    num = 10 * num + s[i++] - '0';
                }
                result += oper.back() * num;
                oper.pop_back();
                i--;
            }
            else if(s[i] == ')'){
                oper.pop_back();
            }
            else if(s[i] != ' '){
                oper.push_back(oper.back() * (s[i] == '-' ? -1 : 1));
            }
        }
        return result;
    }
};
