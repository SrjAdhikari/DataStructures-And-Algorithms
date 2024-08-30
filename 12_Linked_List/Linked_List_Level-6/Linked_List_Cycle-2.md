# Question : [Linked List Cycle II - (LeetCode : 142)](https://leetcode.com/problems/linked-list-cycle-ii/description/)

Given the `head` of a linked list, return _the node where the cycle begins. If there is no cycle, return_ `null`.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to **(0-indexed**). It is `-1` if there is no cycle. **Note that `pos` is not passed as a parameter**.

**Do not modify** the linked list.

### Example 1

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)

```
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```

### Example 2

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png)

```
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```

### Example 3

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png)

```
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
```

### Constraints

-   The number of nodes in the list is in the range `[0, 10^4].`
-   `-10^5 <= Node.val <= 10^5`
-   `pos` is `-1` or a **valid index** in the linked-list.

## Solution

```Cpp
Approach : Using Slow & Fast Pointer Technique

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Handle the cases where the list is empty or has only one node.
        // In both cases, there can be no cycle.
        if(head == NULL || head->next == NULL) {
            return NULL; // Return NULL if there is no cycle.
        }

        // Initialize two pointers, slow and fast, both pointing to the head of the linked list.
        ListNode* slow = head;
        ListNode* fast = head;

        // Iterate through the linked list as long as the fast pointer and the node after the fast pointer are not null.
        // This ensures that 'fast' and 'fast->next' are valid nodes.
        while(fast && fast->next) {
            // Move the slow pointer one step forward.
            slow = slow->next;

            // Move the fast pointer two steps forward.
            fast = fast->next->next;

            // Check if the 'slow' pointer and 'fast' pointer meet at the same node.
            // If they do, it means there is a cycle in the linked list.
            if(slow == fast)
                break; // Exit the loop as soon as a cycle is detected.
        }

        // If 'fast' reaches the end of the list (i.e., 'fast' is NULL or 'fast->next' is NULL),
        // there is no cycle in the list.
        if(fast == NULL || fast->next == NULL)
            return NULL;

        // Move the slow pointer back to the head to find the starting point of the cycle.
        slow = head;

        // Move both pointers one step at a time until they meet.
        // The point where they meet is the start of the cycle.
        while(slow != fast) {
            slow = slow->next;  // Move slow pointer one step forward.
            fast = fast->next;  // Move fast pointer one step forward.
        }

        // Now, 'slow' and 'fast' point to the start of the cycle.

        // Return the node where both pointers meet, either slow or fast which is the start of the cycle.
        return slow;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
