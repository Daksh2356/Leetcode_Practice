/*
Question: 342. Power of Four
Date : 23-10-23
Problem Difficulty level : Easy
Related Topics : Math, Bit Manipulation and Recursion
Problem Statement:
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

Example 1:
Input: n = 16
Output: true

Example 2:
Input: n = 5
Output: false

Example 3:
Input: n = 1
Output: true

Constraints:
-2^31 <= n <= 2^31 - 1

Follow up: Could you solve it without loops/recursion? - ALREADY DONE IN THE BELOW PROVIDED SOLUTION

*/

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;

        while (n > 1)
        {
            if (n % 4 != 0)
                return false;

            n /= 4;
        }

        return true;
    }

    // Time complexity = O(logn)
    // Space complexity = O(1)
};