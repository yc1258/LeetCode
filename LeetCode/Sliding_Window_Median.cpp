/*
 Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
 
 Examples:
 [2,3,4] , the median is 3
 
 [2,3], the median is (2 + 3) / 2 = 2.5
 
 Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.
 
 For example,
 Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 
 Window position                Median
 ---------------               -----
 [1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
 Therefore, return the median sliding window as [1,-1,-1,3,5,6].
 
 Note:
 You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
*/
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    //using multiset for window in case of the very large nums
    //using long for *it in case of the sum of two numbers is over int
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        multiset<int> window;
        if (nums.size() <= 0 || (int)nums.size() < k || k <= 0) {
            return result;
        }
        for (int i = 0; i < k - 1; i++) {
            window.insert(nums[i]);
        }
        for (int i = k - 1; i < nums.size(); i++) {
            window.insert(nums[i]);
            auto it1 = window.begin(),it2 = it1;
            advance(it1, (k-1)/2);
            it2 = it1;
            advance(it2, k % 2 == 0);
            double median = ((long)(*it1) + (*it2)) / 2.0;
            result.push_back(median);
            window.erase(window.find(nums[i + 1 - k]));
        }
        return result;
    }
};
