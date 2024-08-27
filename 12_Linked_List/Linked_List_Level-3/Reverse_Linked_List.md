# Question : [Reverse Linked List - (LeetCode : 206)](https://leetcode.com/problems/reverse-linked-list/description/)

Given the `head` of a singly linked list, reverse the list, and return _the reversed list_.

### Example 1

![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

### Example 2

![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)

```
Input: head = [1,2]
Output: [2,1]
```

### Example 3

```
Input: head = []
Output: []
```

### Constraints

- The number of nodes in the list is the range `[0, 5000].`
- `-5000 <= Node.val <= 5000`

## Solution 1

```Cpp
Approach : Using Extra Space

class Solution {
public:
    // Function to reverse the linked list by modifying the values of the nodes
    ListNode* reverseList(ListNode* head) {
        // Step 1: Store the values of the linked list in a vector
        vector<int> ans;                // Initialize a vector to store the values of the linked list nodes
        ListNode* temp = head;          // Temporary pointer to traverse the list

        // Traverse the linked list and push each node's value into the vector until temp becomes NULL
        while(temp) {
            ans.push_back(temp->val);  // Add the current node's value to the vector
            temp = temp->next;         // Move to the next node
        }

        // Step 2: Reverse the linked list by modifying the node values
        int index = ans.size() - 1;    // Initialize index to the last element in the vector (which corresponds to the original list's last node)
        temp = head;                   // Reset the temp pointer to the head of the list for the second traversal

        // Traverse the linked list again and update each node's value with the corresponding reversed value from the vector
        while(temp) {
            temp->val = ans[index];    // Assign the reversed value to the current node
            index--;                   // Move to the previous element in the vector
            temp = temp->next;         // Move to the next node
        }

        // Step 3: Return the head of the reversed linked list
        return head;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```

## Solution 2

```Cpp
Approach : Without Using Extra Space (In-place)

class Solution {
public:
    // Function to reverse a singly linked list.
    ListNode* reverseList(ListNode* head) {
        // Initialize two pointers: 'curr' for the current node and 'prev' for the previous node.
        ListNode* curr = head;              // Start with the head of the list.
        ListNode* prev = NULL;              // Initially, 'prev' is set to NULL because the new tail will point to NULL.

        // Traverse the linked list until curr becomes NULL.
        while(curr) {
            // Store the next node before changing the next pointer.
            ListNode* next = curr->next;    // 'next' stores the next node of 'curr' pointer in the original list.

            // Reverse the current node's pointer.
            curr->next = prev;              // The current node now points to the previous node, reversing the link.

            // Move the 'prev' pointer one step forward to the current node.
            prev = curr;                    // 'prev' is now set to the current node.

            // Move the 'curr' pointer one step forward to the next node in the original list.
            curr = next;                    // 'curr' moves to the next node.
        }

        // After the loop, 'prev' will be pointing to the new head of the reversed list.
        head = prev;

        // Return the new head of the reversed list.
        return prev;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```

## Solution 3

```Cpp
Approach : Using Recursion

class Solution {
public:
    // Helper function to reverse a singly linked list using recursion
    ListNode* reverseLL(ListNode* curr, ListNode* prev) {
        // Base case: If current node is NULL, return the previous node (new head of reversed list)
        if(curr == NULL){
            return prev;
        }

        // Store the next node in the list before changing the current node's next pointer
        ListNode* next = curr->next;

        // Reverse the current node's pointer to point to the previous node
        curr->next = prev;

        // Move the previous pointer one step forward to the current node
        prev = curr;

        // Move the current pointer one step forward to the next node
        curr = next;

        // Recursively reverse the remaining list
        return reverseLL(curr, prev);
    }

    // Function to initialize the reversal process and call the helper function
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;  // Pointer to the current node (starting at the head of the list)
        ListNode* prev = NULL;  // Pointer to the previous node (initially set to NULL)

        // Call the recursive helper function with the initial pointers
        return reverseLL(curr, prev);
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```
