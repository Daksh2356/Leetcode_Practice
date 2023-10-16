/*
Question : 1269. Number Of Ways To Stay In The Same Place After Some Steps
Date : 15-10-23
Problem Difficulty level : Hard
Related Topics : Dynamic Programming ( Hard Level !! )
Problem Statement:

You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the
array, or stay in the same place (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps.
Since the answer may be too large, return it modulo 109 + 7.


Example 1:
Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay

Example 2:
Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay

Example 3:
Input: steps = 4, arrLen = 2
Output: 8


Constraints:
1 <= steps <= 500
1 <= arrLen <= 10^6
*/

class Solution
{
public:
    int numWays(int steps, int arrLen)
    {

        const int MOD = 1e9 + 7;
        int m = steps;
        int n = min(steps / 2 + 1, arrLen);
        vector<vector<int>> dp(n, vector<int>(m + 1, 0)); // m*n

        dp[0][0] = 1; // stay at the index 0 for 'arrLen' number of times

        for (int j = 1; j <= m; j++) // j = number of steps given
        {
            for (int i = 0; i < n; i++)
            {
                dp[i][j] = dp[i][j - 1]; // for staying at same place
                if (i > 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD; // left by 1 unit ( -1 )
                if (i < n - 1)
                    dp[i][j] = (dp[i][j] + dp[i + 1][j - 1]) % MOD; // right by 1 unit ( +1 )
            }
        }

        return dp[0][steps]; // return the number of ways to reach index 0
    }

    //  time complexity = O(n^2)
    //  space complexity = O(n^2)
};