/*
 Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 
 For example,
 Given nums = [0, 1, 3] return 2.
 
 Note:
 Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

#include <vector>
using std::vector;

class Solution {
public:
    //a smart math mathod
    int missingNumber1(vector<int>& nums) {
        int n = (int)nums.size();
        int total = n*(n+1)/2;
        for (auto &x:nums){
            total -= x;
        }
        return total;
    }
    
    //a xor method
    int missingNumber2(vector<int>& nums) {
        int result = (int)nums.size();
        int i=0;
        
        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }
        
        return result;
    }
};
