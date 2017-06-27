/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 
 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
*/

#include <vector>
using namespace std;

class Solution {
public:
    //there must be a O(n) method using dp
    int maxProduct(vector<int>& nums) {
        int r = nums[0];
        for (int i = 1, imax = r, imin = r; i < nums.size(); i++) {
            if (nums[i] < 0){
                swap(imax, imin);
            }
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);
            r = max(r, imax);
        }
        return r;
    }
};
