# Question : [Linked List Cycle - (LeetCode : 141)](https://leetcode.com/problems/linked-list-cycle/description/)

Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. **Note that `pos` is not passed as a parameter**.

Return `true` _if there is a cycle in the linked list_. Otherwise, return `false`.

### Example 1

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)

```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
```

### Example 2

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png)

```
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
```

### Example 3

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png)

```
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
```

### Constraints

-   The number of nodes in the list is in the range `[0, 10^4].`
-   `-10^5 <= Node.val <= 10^5`
-   `pos` is `-1` or a **valid index** in the linked-list.

## Solution 1

```Cpp
Approach : Brute-force (Using Extra-Space)

class Solution {
public:
    // Function to check if a node has been visited before
    bool isVisited(vector<ListNode*>& visited, ListNode* curr) {
        // Loop through the 'visited' vector to see if the current node 'curr' is in it
        for(int i = 0; i < visited.size(); i++) {
            // If 'curr' is found in the 'visited' vector, return true (1)
            if(visited[i] == curr)
                return true;
        }
        // If 'curr' is not found in the 'visited' vector, return false (0)
        return false;
    }

    // Function to detect if a cycle exists in the linked list
    bool hasCycle(ListNode *head) {
        // Initialize a pointer 'curr' to traverse the linked list, starting at the head
        ListNode* curr = head;

        // Create a vector 'visited' to keep track of nodes that have been visited
        vector<ListNode*> visited;

        // Traverse the linked list until the end is reached
        while(curr) {
            // Check if the current node 'curr' has been visited before
            if(isVisited(visited, curr)) {
                // If 'curr' has been visited, a cycle is detected, so return true
                return true;
            }

            // If 'curr' has not been visited, add it to the 'visited' vector
            visited.push_back(curr);

            // Move 'curr' to the next node in the linked list
            curr = curr->next;
        }

        // If the end of the list is reached without finding a cycle, return false
        return false;
    }
};

Time Complexity = O(N^2)
Space Complexity = O(N)
```

## Solution 2

```Cpp
Approach : Using Unordered_Map

class Solution {
public:
    // Function to detect if a cycle exists in the linked list
    bool hasCycle(ListNode *head) {
        // Create an unordered_map to keep track of visited nodes.
        // The key is the ListNode pointer, and the value is a boolean (true if visited).
        unordered_map<ListNode*, bool> visited;

        // Start from the head of the linked list.
        ListNode* curr = head;

        // Traverse the linked list until the end.
        while(curr) {
            // Check if the current node 'curr' has already been visited.
            if(visited[curr] == true) {
                // If the current node has been visited, a cycle is detected.
                return true; // Return true indicating a cycle exists.
            } else {
                // If the current node has not been visited, mark it as visited.
                visited[curr] = true;
                // Move to the next node in the linked list.
                curr = curr->next;
            }
        }

        // If we reach here, it means there is no cycle in the linked list.
        return false; // Return false indicating no cycle.
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```

## Solution 3

```Cpp
Approach : Using Slow & Fast Pointer Technique

class Solution {
public:
    bool hasCycle(ListNode *head) {
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
                return 1; // Cycle detected.
        }

        // If the loop completes without the 'slow' and 'fast' pointers meeting,
        // it means there is no cycle in the linked list.
        return 0; // No cycle detected.
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
