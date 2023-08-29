/*
Question : 2483. Minimum Penalty for a Shop
Date : 29-08-23
Problem Difficulty level : Medium
Related Topics : String and Prefix Sum
Problem Statement:
You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':

1) if the ith character is 'Y', it means that customers come at the ith hour
2) whereas 'N' indicates that no customers come at the ith hour.

If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

1) For every hour when the shop is open and no customers come, the penalty increases by 1.
2) For every hour when the shop is closed and customers come, the penalty increases by 1.

=> Return the earliest hour at which the shop must be closed to incur a minimum penalty.

** Note that if a shop closes at the jth hour, it means the shop is closed at the hour j. **

Example 1:
Input: customers = "YYNY"
Output: 2
Explanation: 
- Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.

Constraints:
1 <= customers.length <= 105
customers consists only of characters 'Y' and 'N'.
*/

class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0, min_penalty = 0 , best_hour = -1;

        for(int i =0;i<customers.length();i++)
        {
            penalty += customers[i] == 'Y' ? 1 : -1;
            if(penalty > min_penalty)
            {
                min_penalty = penalty;
                best_hour = i;
            }
        }

        return (best_hour +1) ;
    }

    // time complexity = O(N)
    // space complexity = O(1)
};