# Question : [Middle of the Linked List - (LeetCode : 876)](https://leetcode.com/problems/middle-of-the-linked-list/description/)

Given the `head` of a singly linked list, return _the middle node of the linked list_.

If there are two middle nodes, return **the second middle** node.

### Example 1

![](https://assets.leetcode.com/uploads/2021/07/23/lc-midlist1.jpg)

```
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
```

### Example 2

![](https://assets.leetcode.com/uploads/2021/07/23/lc-midlist2.jpg)

```
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
```

### Constraints

- The number of nodes in the list is the range `[1, 100].`
- `1 <= Node.val <= 100`

## Solution 1

```Cpp
Approach : Brute-force

class Solution {
public:
    // Function to calculate the length of the linked list
    int getLength(ListNode* head) {
        ListNode* temp = head;  // Initialize a pointer to traverse the list, starting at the head
        int count = 0;          // Initialize a counter to keep track of the number of nodes

        // Traverse the linked list
        while (temp) {
            count++;            // Increment the counter for each node encountered
            temp = temp->next;  // Move to the next node in the list
        }

        // After the loop, 'count' contains the total number of nodes in the list
        return count;           // Return the total number of nodes
    }

    // Function to find and return the middle node of the linked list
    ListNode* middleNode(ListNode* head) {
        // Step 1: Calculate the total length of the linked list
        ListNode* temp = head;          // Initialize a pointer to traverse the list, starting at the head
        int length = getLength(head);   // Get the total length of the linked list by calling 'getLength'

        // Step 2: Calculate the index of the middle node
        int mid = length / 2;           // Calculate the middle index (integer division to get the floor value)

        // Step 3: Traverse the list again to reach the middle node
        while (mid > 0) {
            mid--;                      // Decrement the middle index. This reduces the count of remaining nodes to skip.
            temp = temp->next;          // Move the pointer 'temp' to the next node in the list.
        }

        // After the loop, 'temp' will point to the middle node of the linked list
        return temp;                    // Return the middle node
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```

## Solution 2

```Cpp
Approach : Slow & Fast Pointer Technique

class Solution {
public:
    // Function to find and return the middle node of a linked list using the slow and fast pointer technique
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;  // Pointer to traverse the list at a slow pace (one step at a time)
        ListNode* fast = head;  // Pointer to traverse the list at a fast pace (two steps at a time)

        // Traverse the list with the 'fast' pointer moving twice as fast as the 'slow' pointer
        while (fast && fast->next) {
            slow = slow->next;           // Move 'slow' one step forward
            fast = fast->next->next;     // Move 'fast' two steps forward
        }

        // When 'fast' reaches the end of the list (or becomes NULL), 'slow' will be at the middle node
        return slow;  // Return the middle node
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
