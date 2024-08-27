# Question : [Remove Nth Node From End of List - (LeetCode : 19)](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)

Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.

### Example 1

![](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

### Example 2

```
Input: head = [1], n = 1
Output: []
```

### Example 3

```
Input: head = [1,2], n = 1
Output: [1]
```

### Constraints

- The number of nodes in the list is the range `sz.`
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

## Solution

```Cpp

class Solution {
public:
    // Function to calculate the total number of nodes in the linked list
    int totalNode(ListNode* head) {
        ListNode* temp = head;      // Initialize a pointer 'temp' to traverse the list starting from 'head'
        int count = 0;              // Initialize a counter to keep track of the number of nodes

        // Traverse the linked list to count the nodes
        while (temp) {
            count++;                // Increment the node count
            temp = temp->next;      // Move to the next node in the list
        }

        // After traversal, 'count' contains the total number of nodes in the list
        return count;               // Return the total node count
    }

    // Function to remove the nth node from the end of the linked list
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Initialize pointers for traversal
        ListNode* curr = head;          // Pointer to traverse the list starting from 'head'
        ListNode* prev = NULL;          // Pointer to keep track of the node just before 'curr'

        // Step 1: Calculate the total number of nodes in the list
        int count = totalNode(head);    // Get the total number of nodes

        // Step 2: Find the position of the node to be removed from the start of the list
        count -= n;                     // Calculate the position of the node to be removed from the start

        // Handle the edge case where the node to be removed is the head
        if (count == 0) {
            // If the head node is to be removed, update head to the next node
            ListNode* temp = head;      // Store the current head node
            head = temp->next;          // Update the head to the next node
            delete temp;                // Delete the old head node to free memory
            return head;                // Return the updated head of the list
        }

        // Step 3: Traverse to the node just before the one to be removed
        while (count) {
            prev = curr;                // Update the 'prev' pointer to the current node
            curr = curr->next;          // Move 'curr' to the next node
            count--;                    // Decrement the remaining count
        }

        // Step 4: Remove the nth node from the end
        prev->next = curr->next;        // Skip the node to be removed by linking 'prev' to 'curr->next'
        delete curr;                    // Delete the 'curr' node to free memory

        // Return the updated head of the list
        return head;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
