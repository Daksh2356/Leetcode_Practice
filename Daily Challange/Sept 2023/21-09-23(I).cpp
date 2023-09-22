/*
Question : 4. Median of Two Sorted Arrays
Date : 21-09-23
Problem Difficulty level : Hard
Related Topics: Array, Binary Search, Divide and Conquer

Problem Statement:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/
// BRUTE FORCE APPROACH

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        double val = 0.0;
        vector<int> nums3(nums1);

        for (int j = 0; j < n; j++)
        {
            nums3.push_back(nums2[j]);
        }

        sort(nums3.begin(), nums3.end());

        int N = nums3.size();

        if (N % 2 != 0)
            val = nums3[(N - 1) / 2];
        else
            val = (nums3[N / 2] + nums3[N / 2 - 1]) / 2.0;

        return val;
    }
};

// time complexity =  O((m + n) log(m + n))
// space complexity = O(m + n)
