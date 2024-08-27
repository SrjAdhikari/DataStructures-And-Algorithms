# Question : [Palindrome Linked List - (LeetCode : 234)](https://leetcode.com/problems/palindrome-linked-list/description/)

Given the `head` of a singly linked list, return `true` _if it is a palindrome or_ `false` _otherwise_.

### Example 1

![](https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg)

```
Input: head = [1,2,2,1]
Output: true
```

### Example 2

![](https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg)

```
Input: head = [1,2]
Output: false
```

### Constraints

- The number of nodes in the list is the range `[1, 10^5].`
- `0 <= Node.val <= 9`

## Solution

```Cpp

class Solution {
public:
    // Function to calculate the total number of nodes in the linked list
    int findLength(ListNode* head) {
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

    // Function to check if the linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        // Edge case: If the list has only one node, it is trivially a palindrome
        if (head->next == NULL) {
            return true;                // Return true as a single node list is a palindrome
        }

        // Initialize pointers for traversing and manipulating the list
        ListNode* curr = head;          // Pointer to traverse the list from the start
        ListNode* prev = NULL;          // Pointer to keep track of the previous node in the traversal

        // Step 1: Find the length of the list
        int count = findLength(head);   // Get the total number of nodes
        count /= 2;                     // Calculate half the length of the list to determine the midpoint

        // Step 2: Traverse to the midpoint of the list
        while (count) {
            prev = curr;                // Update 'prev' to the current node (the last node of the first half)
            curr = curr->next;          // Move 'curr' to the next node
            count--;                    // Decrement the count until we reach the midpoint
        }

        // At this point, 'prev' is the last node of the first half, and 'curr' is the start of the second half

        // Step 3: Split the list into two halves
        prev->next = NULL;              // Terminate the first half of the list by setting 'prev->next' to NULL

        // Step 4: Reverse the second half of the list, 'curr' is pointing to it
        while (curr) {
            ListNode* next = curr->next;    // Store the next node
            curr->next = prev;              // Reverse the link by pointing to the previous node
            prev = curr;                    // Move 'prev' to the current node
            curr = next;                    // Move to the next node
        }

        // Now 'prev' is now pointing to the head of the reversed second half of the list
        // 'head' still points to the start of the first half of the list

        // Step 5: Compare the two halves of the list
        ListNode* head1 = head;             // Pointer to traverse the first half of the list
        ListNode* head2 = prev;             // Pointer to traverse the reversed second half

        // Compare nodes from the start of both halves
        while (head1) {
            if (head1->val != head2->val) {
                return 0;                   // Return 0 if values do not match, indicating it's not a palindrome
            } else {
                head1 = head1->next;        // Move to the next node in the first half
                head2 = head2->next;        // Move to the next node in the reversed second half
            }
        }

        // If we have reached the end of both halves and all values matched, return true
        return true;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
