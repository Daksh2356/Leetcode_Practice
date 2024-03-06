/*
Question :141. Linked List Cycle II
Date : 06-03-24
Problem Difficulty level : Medium
Related Topics : Hash Table, Linked List and Two Pointers
Problem Statement:
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. 
Note that pos is not passed as a parameter.

Do not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 
Constraints:
The number of the nodes in the list is in the range [0, 10^4].
-10^5 <= Node.val <= 10^5
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

// CODE : 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr; // No "cycle" if no. of nodes < 2

        ListNode *slow = head, *fast = head; // two pointers [TORTOISE AND HARE ALGO]

        while(fast && fast->next){
            slow = slow->next;
            fast=fast->next->next;

            if(slow == fast) break;  // Cycle found
        }

        if(!fast || !fast->next) return nullptr; // No cycle if end of list is reached

        fast = head;      // reset one of the pointers (slow/ fast) to head
        while(slow != fast){
            slow = slow->next;   // move slow and fast at same pace untill they meet
            fast = fast->next;
        }

        return slow;    // return node where the cycle begins

        // time complexity = O(n) (linear)
        // space complexity = O(1) (constant additional space used)
    }
};