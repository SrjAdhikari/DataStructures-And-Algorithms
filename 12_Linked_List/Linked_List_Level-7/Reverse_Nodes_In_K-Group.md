# Question : [Reverse Nodes in k-Group - (LeetCode : 25)](https://leetcode.com/problems/reverse-nodes-in-k-group/description/)

Given the `head` of a linked list, reverse the nodes of the list `k` at a time, and return _the modified list_.

`k` is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of `k` then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

### Example 1

![](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg)

```
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
```

### Example 2

![](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg)

```
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
```

### Constraints

-   The number of nodes in the list is `n`.
-   `1 <= k <= n <= 5000`
-   `0 <= Node.val <= 1000`

**Follow-up**: Can you solve the problem in `O(1)` extra memory space?

## Solution

```Cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case: If the list is empty or k is 1, no need to reverse anything.
        if (head == NULL || k == 1) return head;

        // Initialize pointers.
        ListNode* curr = head;      // Pointer to traverse the list.
        int count = 0;              // Counter to count nodes in the current segment.

        // First, count the number of nodes in the list segment.
        // Move 'curr' forward k times to see if there are at least k nodes.
        while (curr && count < k) {
            curr = curr->next;      // Move to the next node.
            count++;                // Increment the counter.
        }

        // If there are less than k nodes left, return the head as is (no reversal needed).
        if (count < k) return head;

        // If we have k nodes, we need to reverse this segment.

        // Initialize pointers for reversal.
        ListNode* prev = NULL;  // Pointer to the previous node (start as NULL for the first node).
        ListNode* next = NULL;  // Pointer to the next node of "curr"
        curr = head;            // Reset 'curr' to the start of the segment.
        count = k;              // Reset count to k for reversal.

        // Reverse the nodes in this segment.
        while (count > 0) {
            next = curr->next;    // Store the next node (to avoid losing it).
            curr->next = prev;    // Reverse the link: make the current node point to the previous node.
            prev = curr;          // Move 'prev' to the current node (current node becomes the previous one for the next iteration).
            curr = next;          // Move to the next node in the original list.
            count--;              // Decrement the counter.
        }

        // Now 'prev' points to the new head of the reversed segment.
        // 'head' is the end of the reversed segment.
        // Recursively reverse the rest of the list and link it to the end of the reversed segment.
        head->next = reverseKGroup(curr, k);

        // Return the new head of the reversed segment (prev is the new head after reversal).
        return prev;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
