/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
#include <vector>
using std::vector;

class Solution {
public:
	//a recursive solution
    vector<vector<int>> generateMatrix(int n) {
     	vector<vector<int> > vec(n, vector<int>(n));
		if (n == 0)
		{
			return vec;
		}
		else if (n == 1)
		{
			vec[0][0] = 1;
			return vec;
		}
		int c = 0;
		for (int i = 0; i < n - 1; i++)
		{
			vec[0][i] = ++c;
		}
		for (int i = 0; i < n - 1; i++)
		{
			vec[i][n - 1] = ++c;
		}
		for (int i = n - 1; i > 0; i--)
		{
			vec[n - 1][i] = ++c;
		}
		for (int i = n - 1; i > 0; i--)
		{
			vec[i][0] = ++c;
		}
		vector<vector<int>> sub_vec = generateMatrix(n - 2);
		for (int i = 0; i < n - 2; i++)
		{
			for (int j = 0; j < n - 2; j++)
			{
				vec[i + 1][j + 1] = sub_vec[i][j] + c;
			}
		}
		return vec;	
	}

	//a iteration solution
	vector<vector<int>> generateMatrix1(int n) {
		vector<vector<int>> arr(n, vector<int>(n));
		int i = 0, j = 0, k = 1;
		if (n == 1) {
			arr[i][j] = k;
		}
		while (k < n*n) {
			for (; j < n - i - 1; j++) {
				arr[i][j] = k++;
			}
			for (; i < j; i++) {
				arr[i][j] = k++;
			}
			for (; j > n - i - 1; j--) {
				arr[i][j] = k++;
			}
			for (; i > j; i--) {
				arr[i][j] = k++;
			}
			i++;
			j++;
			if (k == n*n) {
				arr[i][j] = n*n;
			}
		}
		return arr;
	}
};
