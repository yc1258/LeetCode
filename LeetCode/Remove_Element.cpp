/*
 Given an array and a value, remove all instances of that value in place and return the new length.
 
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */
#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    //using STL
    int removeElement(vector<int>& nums, int val) {
        for (vector<int>::iterator iter = nums.begin();iter != nums.end();iter++){
            if (*iter == val) {
                nums.erase(iter--);
            }
        }
        return nums.size();
    }
    
    //a simple solution
    int removeElement2(vector<int>& nums, int val) {
        int i=0;
        for (int j=0; j<nums.size(); j++){
            if (nums[j] != val)
                nums[i++]=nums[j];
        }
        return i;
    }
};