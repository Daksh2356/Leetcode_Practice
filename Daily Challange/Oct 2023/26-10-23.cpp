/*
Question: 823. Binary Tree with Factors
Date : 26-10-23
Problem Difficulty level : Medium
Related Topics : Array, Hash Table, DP, Sorting
Problem Statement:

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be
equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

Example 1:
Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]

Example 2:
Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].


Constraints:
1 <= arr.length <= 1000
2 <= arr[i] <= 10^9
All the values of arr are unique.
*/

const int MOD = 1e9 + 7;

class Solution
{
public:
    int numFactoredBinaryTrees(std::vector<int> &arr)
    {
        std::sort(arr.begin(), arr.end());
        std::unordered_set<int> s(arr.begin(), arr.end());
        std::unordered_map<int, int> dp;
        for (int x : arr)
            dp[x] = 1;

        for (int i : arr)
        {
            for (int j : arr)
            {
                if (j > std::sqrt(i))
                    break;
                if (i % j == 0 && s.find(i / j) != s.end())
                {
                    long long temp = (long long)dp[j] * dp[i / j];
                    if (i / j == j)
                    {
                        dp[i] = (dp[i] + temp) % MOD;
                    }
                    else
                    {
                        dp[i] = (dp[i] + temp * 2) % MOD;
                    }
                }
            }
        }

        int result = 0;
        for (auto &[_, val] : dp)
        {
            result = (result + val) % MOD;
        }
        return result;
    }

    // Time complexity = O(n^2) - two for loops 
    // Space complexity = O(n) - set and map
};