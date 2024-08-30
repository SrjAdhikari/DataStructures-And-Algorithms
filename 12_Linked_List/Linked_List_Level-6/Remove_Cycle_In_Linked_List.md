# Question : [Remove loop in Linked List - GFG](https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1)

Given the head of a linked list that may contain a loop. A loop means that the last node of the linked list is connected back to a node in the same list. So if the next of the previous node is null. then there is no loop. Remove the loop from the linked list, if it is present (we mainly need to make the next of the last node null). Otherwise, keep the linked list as it is.

**Note**: Given an integer, `pos` (1 based index) Position of the node to which the last node links back if there is a loop. If the linked list does not have any loop, then `pos` = 0.

The generated output will be `true` if your submitted code is correct, otherwise, `false`.

### Example 1

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700332/Web/Other/blobid0_1718609709.png)

```
Input: Linked list: 1->3->4, pos = 2
Output: true
Explanation: A loop is present. If you remove it successfully, the answer will be true.
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700332/Web/Other/blobid0_1718609876.png)

```
Input: Linked list: 1->8->3->4, pos = 0
Output: true
Explanation: The Linked list does not contains any loop.
```

### Example 3

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700332/Web/Other/blobid2_1718609744.png)

```
Input: Linked list: 1->2->3->4, pos = 1
Output: true
Explanation: A loop is present. If you remove it successfully, the answer will be true.
```

```
Expected Time Complexity :  O(n)
Expected Auxiliary Space :  O(1)
```

### Constraints

`1 ≤ size of linked list ≤ 10^5`

## Solution

```Cpp
Approach : Slow & Fast Pointer Technique

class Solution {
public:
    void removeLoop(Node* head) {
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
            return;

        // Move the slow pointer back to the head to find the starting point of the cycle.
        slow = head;

        // Move both pointers one step at a time until they meet.
        // The point where they meet is the start of the cycle.
        while(slow != fast) {
            slow = slow->next;  // Move slow pointer one step forward.
            fast = fast->next;  // Move fast pointer one step forward.
        }

        // Now, 'slow' and 'fast' point to the start of the cycle.

        // Find the node just before the start of the cycle to break the loop.
        // Move the slow pointer to the last node in the cycle.
        while(slow->next != fast) {
            slow = slow->next;  // Move slow pointer one step forward.
        }

        // Break the loop by setting the next of the last node in the cycle to NULL.
        slow->next = NULL;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
