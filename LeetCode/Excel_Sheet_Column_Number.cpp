/*
 Related to question Excel Sheet Column Title
 
 Given a column title as appear in an Excel sheet, return its corresponding column number.
 
 For example:
 
 A -> 1
 B -> 2
 C -> 3
 ...
 Z -> 26
 AA -> 27
 AB -> 28
 Credits:
 Special thanks to @ts for adding this problem and creating all test cases.
*/

#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            num = s[i] - 'A' + 1 + num * 26;
        }
        return num;
    }
};
