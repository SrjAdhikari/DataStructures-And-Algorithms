# Question : [Rotate List - (LeetCode : 61)](https://leetcode.com/problems/rotate-list/description/)

Given the `head` of a linked list, rotate the list to the right by `k` places.

### Example 1

![](https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg)

```
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
```

### Example 2

![](https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg)

```
Input: head = [0,1,2], k = 4
Output: [2,0,1]
```

### Constraints

- The number of nodes in the list is the range `[0, 500].`
- `-100 <= Node.val <= 100`
- `0 <= k <= 2 * 10^9`

## Solution

```Cpp

class Solution {
public:
    // Function to calculate the length of the linked list
    int findLength(ListNode* head) {
        ListNode* temp = head;  // Pointer to traverse the list
        int count = 0;          // Counter to keep track of the number of nodes

        // Traverse the linked list
        while (temp) {
            count++;            // Increment the counter for each node encountered
            temp = temp->next;  // Move to the next node
        }

        // Return the total number of nodes in the list
        return count;
    }

    // Function to rotate the linked list to the right by k places
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge case: If the list is empty or has only one node, no rotation is needed
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* curr = head;          // Pointer to traverse the list from the start
        ListNode* prev = NULL;          // Pointer to keep track of the node before the rotation point

        // Step 1: Calculate the length of the linked list
        int length = findLength(head);  // Get the total length of the list

        // Step 2: Calculate the effective number of rotations needed
        k = k % length;                 // Normalize k to ensure it's within the length of the list

        // If k is 0, the list does not need rotation (either already in the correct position or rotation is a multiple of the list length)
        if (k == 0) {
            return head;
        }

        // Step 3: Find the new tail of the list after rotation
        length -= k;                    // Adjust the length to find the rotation point (The position of the new tail node)

        // Traverse the list to find the new tail node
        while (length) {
            prev = curr;                // Update the 'prev' pointer to the current node
            curr = curr->next;          // Move 'curr' pointer one step forward
            length--;                   // Decrement the remaining length until reaching the new tail
        }

        // Step 4: Split the list into two parts
        prev->next = NULL;              // End the first part of the list by setting 'prev->next' to NULL

        // Step 5: Find the last node of the new list (originally the start of the list)
        ListNode* tail = curr;          // 'curr' points to the start of the second part of the list
        while (tail->next) {
            tail = tail->next;          // Move to the end of the second part
        }

        // Step 6: Connect the tail of the second part to the head of the first part
        tail->next = head;              // Append the first part to the end of the second part
        head = curr;                    // Update 'head' to the start of the second part, which is the new head of the rotated list

        // Return the new head of the rotated list
        return head;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
